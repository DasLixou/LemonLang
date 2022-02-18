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
            if (taste(TokenType.ID)) // (statement: (assignment | functionCall) ";")
            {
                string name = eat(TokenType.ID).value;
                if (taste(TokenType.EQUALS)) // assignment
                {
                    eat(TokenType.EQUALS);
                    Object value = eat(TokenType.INT).value;
                    eat(TokenType.SEMICOLON);
                    return new AST(ASTType.ASSIGNMENT, name, value);

                }
                else // functionCall
                {
                    ArrayList arguments = parseArgumentList();
                    eat(TokenType.SEMICOLON);
                    return new AST(ASTType.FUNCTION_CALL, name, arguments);
                }
            }
            else if (taste(TokenType.KW_FUNC)) // (functionDeclaration | ifBlock)
            {
                eat(TokenType.KW_FUNC);
                string name = eat(TokenType.ID).value;
                parseParameterList();
                ArrayList value = parseBlock();
                return new AST(ASTType.FUNCTION_DECLARATION, name, value);
            }
            else
            {
                throw new Exception("Instruction isn't Assignment or Function Declaration");
            }
        }

        private ArrayList parseArgumentList()
        {
            eat(TokenType.LPAREN);
            ArrayList values = new ArrayList();
            while (taste(TokenType.RPAREN) == false)
            {
                values.Add(eat());
                if (taste(TokenType.RPAREN) == false) { eat(TokenType.COMMA); }
            }
            eat(TokenType.RPAREN);
            return values;
        }

        private ArrayList parseParameterList()
        {
            eat(TokenType.LPAREN);
            ArrayList values = new ArrayList();
            while (taste(TokenType.RPAREN) == false)
            {
                Token type = eat(TokenType.ID);
                Token name = eat(TokenType.ID);
                values.Add((type, name));
                if (taste(TokenType.RPAREN) == false) { eat(TokenType.COMMA); }
            }
            eat(TokenType.RPAREN);
            return values;
        }

        private ArrayList parseBlock()
        {
            eat(TokenType.LBRACE);
            ArrayList instructions = new ArrayList();
            while (taste(TokenType.RBRACE) == false)
            {
                instructions.Add(parseInstruction());
            }
            eat(TokenType.RBRACE);
            return instructions;
        }

        // Utils

        private Token eat()
        {
            Token result = this.token;
            this.token = lexer.nextToken();
            return result;
        }

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