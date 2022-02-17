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
            while (currentIndex < srcLength && currentChar != '\0')
            {
                trySkipWhitespace();

                if (Char.IsLetter(currentChar))
                {
                    return lexID();
                }
                if (Char.IsDigit(currentChar))
                {
                    return lexNumber();
                }
                switch (currentChar)
                {
                    case '"':
                        return lexString();
                    case '=':
                        return advanceCurrent(TokenType.EQUALS);
                    case '#':
                        return advanceCurrent(TokenType.HASHTAG);
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
                        return advanceCurrent(TokenType.EOF);
                    default:
                        throw new Exception($"Invalid character '{currentChar}'");

                }
            }
            return new Token("", TokenType.EOF);
        }

        // Custom Lexer Parts

        public Token lexID()
        {
            string value = "";
            while (Char.IsLetter(currentChar))
            {
                value = $"{value}{currentChar}";
                advance();
            }
            switch (value.ToLower())
            {
                case "func":
                    return new Token(value, TokenType.KW_FUNC);
            }
            return new Token(value, TokenType.ID);
        }

        public Token lexString()
        {
            string value = "";
            eat('"');
            while (!taste('"'))
            {
                value += currentChar;
                advance();
            }
            eat('"');
            return new Token(value, TokenType.STRING);
        }

        public Token lexNumber()
        {
            string value = "";
            while (Char.IsDigit(currentChar))
            {
                value = $"{value}{currentChar}";
                advance();
            }
            return new Token(value, TokenType.INT);
        }

        // Utils

        private void eat(char c)
        {
            if (this.currentChar != c)
            {
                throw new Exception("Expected character '" + c + "' but got '" + this.currentChar + "'");
            }

            advance();
        }

        private bool taste(char c)
        {
            return this.currentChar == c;
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