namespace LemoncNS
{
    public class Lexer
    {
        public string src { get; }
        public uint srcLength { get; }
        public uint currentIndex { get; private set; }
        public char currentChar { get; private set; }

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

        public Token nextToken()
        {
            while (currentChar != '\0')
            {
                trySkipWhitespace();

                if (Char.IsLetter(currentChar))
                {

                }
                if (Char.IsDigit(currentChar))
                {

                }
                switch (currentChar)
                {
                    case '=':
                        return advanceCurrent(TokenType.EQUALS);
                    case '(':
                        return advanceCurrent(TokenType.LPAREN);
                    case ')':
                        return advanceCurrent(TokenType.RPAREN);
                    case '{':
                        return advanceCurrent(TokenType.LBRACE);
                    case '}':
                        return advanceCurrent(TokenType.RBRACE);
                    case ',':
                        return advanceCurrent(TokenType.COMMA);
                    case ';':
                        return advanceCurrent(TokenType.SEMICOLON);
                    case '\0':
                        break;
                    default:
                        throw new Exception($"Invalid character '{currentChar}'");
                }
            }

            throw new Exception($"Invalid character '${currentChar}'");
        }

        private void trySkipWhitespace()
        {
            while (currentChar == 13 || currentChar == 10 || currentChar == ' ' || currentChar == '\t')
            {
                advance();
            }
        }

        private Token advanceCurrent(TokenType type)
        {
            Token token = new Token("" + currentChar, type);
            advance();
            return token;
        }

    }
}