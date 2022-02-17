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
                    eat(TokenType.LPAREN);
                    // TODO: Parse Parameters
                    eat(TokenType.RPAREN);
                    eat(TokenType.SEMICOLON);
                    return new AST(ASTType.FUNCTION_CALL, name, (short)0);
                }
            }
            else if (taste(TokenType.KW_FUNC)) // (functionDeclaration | ifBlock)
            {
                eat(TokenType.KW_FUNC);
                string name = eat(TokenType.ID).value;
                eat(TokenType.LPAREN);
                // TODO: Parse Parameters
                eat(TokenType.RPAREN);
                eat(TokenType.LBRACE);
                ArrayList value = parseBlock();
                eat(TokenType.RBRACE);
                return new AST(ASTType.FUNCTION_DECLARATION, name, value);
            }
            else
            {
                throw new Exception("Instruction isn't Assignment or Function Declaration");
            }
        }

        private ArrayList parseBlock()
        {
            ArrayList instructions = new ArrayList();
            while (taste(TokenType.RBRACE) == false)
            {
                instructions.Add(parseInstruction());
            }
            eat(TokenType.RBRACE);
            return instructions;
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