using System.Collections;

namespace LemoncNS
{
    public class Compiler
    {
        public static string compileFasmWindows32(AST structure)
        {
            string value = "";
            switch (structure.type)
            {
                case ASTType.NOOP:
                    value = "";
                    foreach (AST ast in ((ArrayList)structure.value))
                    {
                        value += compileFasmWindows32(ast);
                    }
                    break;
                case ASTType.ASSIGNMENT:
                    value = "";
                    break;
                case ASTType.FUNCTION_DECLARATION:
                    value = "";
                    break;
                default:
                    throw new Exception("Type " + structure.type + " is not supported for compileFasmWindows32");
            }
            return value;
        }
    }
}