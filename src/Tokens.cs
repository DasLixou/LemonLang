namespace LemoncNS
{
    public class Token
    {
        public string value { get; }
        public TokenType type { get; }

        public Token(string value, TokenType type)
        {
            this.value = value;
            this.type = type;
        }
    }

    public enum TokenType
    {
        ID,
        // Keywords
        KW_PUBLIC,
        KW_FUNC,
        // Types
        INT,
        STRING,
        // Symbols
        EQUALS,
        HASHTAG,
        LPAREN,
        RPAREN,
        LBRACE,
        RBRACE,
        COMMA,
        SEMICOLON,
        EOF,
    }

}
