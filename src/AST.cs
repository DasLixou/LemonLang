namespace LemoncNS
{
    public class AST
    {
        public string name { get; set; }
        public Object value { get; set; }
        public ASTType type { get; set; }

        public AST(ASTType type)
        {
            this.type = type;
            this.name = "";
            this.value = (byte)0;
        }

        public AST(ASTType type, string name, Object value)
        {
            this.type = type;
            this.name = name;
            this.value = value;
        }

        public AST(ASTType type, string name, params Object[] values)
        {
            this.type = type;
            this.name = name;
            this.value = values;
        }
    }

    public enum ASTType
    {
        NOOP,
        ASSIGNMENT,
        FUNCTION_CALL,
        FUNCTION_DECLARATION,
        IF_STATEMENT
    }
}