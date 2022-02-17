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
                    break;
                default:
                    throw new Exception("Type " + structure.type + " is not supported for simulating.");
            }
        }
    }
}