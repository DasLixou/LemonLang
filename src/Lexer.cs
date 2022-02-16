namespace LemoncNS
{
    public class Lexer
    {
        public string src { get; }
        public uint srcLength { get; }
        public uint currentIndex { get; private set; }
        public char? currentChar { get; private set; }

        public Lexer(string src)
        {
            this.src = src;
            this.srcLength = (uint)src.Length;
            this.currentIndex = 0;
            if (currentIndex >= srcLength) throw new Exception("Source has no characters.");
            this.currentChar = src[(int)this.currentIndex];
        }

        public bool advance()
        {
            this.currentIndex += 1;

            if (currentIndex >= srcLength) return false;

            this.currentChar = src[(int)this.currentIndex];

            return true;
        }

    }
}