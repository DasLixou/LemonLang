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
            AST ast = new AST(ASTType.NOOP, "", new ArrayList());
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
            if (taste(TokenType.ID))
            {
                string name = eat(TokenType.ID).value;
                eat(TokenType.EQUALS);
                Object value = eat(TokenType.INT).value;
                eat(TokenType.SEMICOLON);
                return new AST(ASTType.ASSIGNMENT, name, value);
            }
            else if (taste(TokenType.KW_FUNC))
            {
                eat(TokenType.KW_FUNC);
                string name = eat(TokenType.ID).value;
                eat(TokenType.LPAREN);
                // TODO: Parse Parameters
                eat(TokenType.RPAREN);
                eat(TokenType.LBRACE);
                // TODO: Parse Block Statements
                eat(TokenType.RBRACE);
                return new AST(ASTType.FUNCTION_DECLARATION, name, (short)0);
            }
            else
            {
                throw new Exception("Instruction isn't Assignment or Function Declaration");
            }
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