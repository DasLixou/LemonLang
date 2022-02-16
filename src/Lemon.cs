using LemoncNS;

class Lemonc
{
    static int Main(string[] args)
    {
        Console.WriteLine("[lemonc] Start compiling...");
        Lexer lexer = new Lexer(System.IO.File.ReadAllText(args[0]));
        Parser parser = new Parser(lexer);
        AST structure = parser.parse();
        System.IO.File.WriteAllText("lemon_application.asm", Compiler.compileFasmWindows32(structure));
        return 0;
    }
}
