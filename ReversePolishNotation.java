 import java.util.*; 
 import java.lang.Character.*;

 public class ReversePolishNotation
 {
    static Scanner input = new Scanner(System.in);

    public static void main(String []args)
    {
        System.out.println("Type Equation > ");
        String equation = input.next();

        parseEquation(equation);
    }

    private static void parseEquation(String equation)
    {
        ArrayList<String> postfix = new ArrayList<String>();

        Map<Character, Integer> signs = new HashMap<Character, Integer>();
        signs.put('+', 1);
        signs.put('-', 1);
        signs.put('*', 2);
        signs.put('/', 2);
        signs.put('^', 3);

        String buffer = "";
        Stack<Character> operators = new Stack<Character>();

        for(char a: equation.toCharArray())
        {
            if(Character.isDigit(a))
              buffer += a;

            else if(a == '(')
              operators.push('(');

            else if(a == ')')
            {
                if(buffer.length() > 0)
                {
                    postfix.add(buffer);
                    buffer = "";
                }

                while(operators.empty() || operators.peek() != '(')
                {
                    postfix.add(operators.peek().toString());
                    operators.pop();
                }

                operators.pop();
            }

            else
            {
                if(buffer.length() > 0)
                {
                  postfix.add(buffer);
                  buffer = "";
                }

                while(operators.empty() == false && operators.peek() != '(' && signs.get(operators.peek()) >= signs.get(a))
                {
                    postfix.add(operators.peek().toString());
                    operators.pop();
                }

                operators.push(a);
            }
        }

        while(operators.empty() == false)
        {
            if(buffer.length() > 0)
            {
              postfix.add(buffer);
              buffer = "";
            }

            postfix.add(operators.peek().toString());
            operators.pop();
        }

        evaluatePostfix(postfix);
    }

    private static void evaluatePostfix(ArrayList<String> postfix)
    {
      List<String> operators = Collections.unmodifiableList(Arrays.asList("+", "-", "*", "/", "^"));
      Stack<Integer> operands = new Stack<Integer>();

      int a,b,c = 0;

      for(String s: postfix)
      {
          if(operators.contains(s) == false)
              operands.push(Integer.parseInt(s));

          else
          {
              a = operands.peek();
              operands.pop();
              b = operands.peek();
              operands.pop();

              if(s.equals("+"))
                c = a + b;

              if(s.equals("-"))
                  c = b - a;

              if(s.equals("*"))
                  c = a * b;

              if(s.equals("/"))
                  c = b / a;

              operands.push(c);
          }
      }

      System.out.println(operands.peek());
    }
 }
