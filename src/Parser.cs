using System.Collections;

namespace LemoncNS
{
    public class Parser
    {
        public Token token { get; set; }
        public Lexer lexer { get; }

        public Parser(Lexer lexer)
        {
            this.lexer = lexer;
            this.token = lexer.nextToken();
        }

        public AST parse()
        {
            AST ast = new AST("", new ArrayList());
            while (token.type != TokenType.EOF)
            {
                ((ArrayList)ast.value).Add(parseInstruction());
            }
            return ast;
        }

        // Custom parsing functions

        // Definition instruction: (statement: (assignment | functionCall) ";") | (functionDeclaration | ifBlock)
        private AST parseInstruction()
        {
            string name = "";
            Object value = "";
            if (taste(TokenType.ID))
            {
                name = eat(TokenType.ID).value;
                eat(TokenType.EQUALS);
                value = eat(TokenType.INT).value;
                eat(TokenType.SEMICOLON);
            }
            return new AST(name, value);
        }

        // Utils

        private Token eat(TokenType type)
        {
            if (this.token.type != type)
            {
                throw new Exception("Expected type '" + type + "' but got '" + token.type + "'");
            }

            Token result = this.token;
            this.token = lexer.nextToken();
            return result;
        }

        private bool taste(TokenType type)
        {
            if (this.token.type == type)
            {
                return true;
            }
            return false;
        }
    }
}