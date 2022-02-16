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
    }

    public enum ASTType
    {
        NOOP,
        ASSIGNMENT,
        FUNCTION_DECLARATION,
    }
}