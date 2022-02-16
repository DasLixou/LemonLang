using LemoncNS;

Console.WriteLine("[lemonc] Start compiling...");
Lexer lexer = new Lexer("test");

Console.WriteLine("[lemonc] " + lexer.currentChar);
while (lexer.advance())
{
    Console.WriteLine("[lemonc] " + lexer.currentChar);
}