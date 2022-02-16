using LemoncNS;

Console.WriteLine("[lemonc] Start compiling...");
Lexer lexer = new Lexer("=    ;");

Console.WriteLine("[lemonc] " + lexer.nextToken().type);
Console.WriteLine("[lemonc] " + lexer.nextToken().type);