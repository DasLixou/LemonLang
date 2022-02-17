using LemoncNS;

class Lemonc
{
    static int Main(string[] args)
    {
        if (args.Length != 2)
        {
            sendHelp();
        }
        else if (args[0] == "simulate")
        {
            Console.WriteLine("[lemonc] Start simulating...");
            Lexer lexer = new Lexer(System.IO.File.ReadAllText(args[1]));
            Parser parser = new Parser(lexer);
            AST structure = parser.parse();
            Interpreter.interpret(structure);
            return 0;
        }
        else if (args[0] == "compile")
        {
            Console.WriteLine("[lemonc] Start compiling...");
            Lexer lexer = new Lexer(System.IO.File.ReadAllText(args[1]));
            Parser parser = new Parser(lexer);
            AST structure = parser.parse();
            System.IO.File.WriteAllText("lemon_application.asm", Compiler.compileFasmWindows32(structure));
            return 0;
        }
        else
        {
            sendHelp();
        }
        return 1;
    }

    static void sendHelp()
    {

        Console.WriteLine("[lemonc] Wrong arguments.");
        Console.WriteLine("[lemonc] Expected:");
        Console.WriteLine("[lemonc] => lemonc simulate <filename>");
        Console.WriteLine("[lemonc] => lemonc compile <filename>");
    }
}
