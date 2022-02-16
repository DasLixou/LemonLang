using LemoncNS;

Console.WriteLine("[lemonc] Start compiling...");
Lexer lexer = new Lexer("hello = 0;");
Parser parser = new Parser(lexer);

AST ast = parser.parse();

Token token;
while ((token = lexer.nextToken()).type != TokenType.EOF)
{
    Console.WriteLine("[lemonc] <type='" + token.type + "' value='" + token.value + "'>");
}