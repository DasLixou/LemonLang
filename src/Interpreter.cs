using System.Collections;

namespace LemoncNS
{
    public class Interpreter
    {
        public static void interpret(AST structure)
        {
            switch (structure.type)
            {
                case ASTType.NOOP:
                    foreach (AST ast in ((ArrayList)structure.value))
                    {
                        interpret(ast);
                    }
                    break;
                case ASTType.ASSIGNMENT:
                    break;
                case ASTType.FUNCTION_DECLARATION:
                    foreach (AST ast in ((ArrayList)structure.value))
                    {
                        interpret(ast);
                    }
                    break;
                case ASTType.FUNCTION_CALL:
                    if (structure.name == "print")
                    {
                        Token? token = ((ArrayList)structure.value)[0] as Token;
                        Console.WriteLine(token?.value);
                    }
                    break;
                default:
                    throw new Exception("Type " + structure.type + " is not supported for simulating.");
            }
        }
    }
}