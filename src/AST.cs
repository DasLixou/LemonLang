namespace LemoncNS
{
    public class AST
    {
        public string name { get; set; }
        public Object value { get; set; }

        public AST(string name, Object value)
        {
            this.name = name;
            this.value = value;
        }
    }
}