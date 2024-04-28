#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

// Enumeración para los tipos de tokens
enum class TokenType {
    IF,
    ELSE,
    SWITCH,
    CASE,
    DEFAULT,
    FOR,
    WHILE,
    IDENTIFIER,
    FUNCTION,
    VARIABLE,
    SEMICOLON,
    OPEN_BRACE,
    CLOSE_BRACE,
    OPEN_PAREN,
    CLOSE_PAREN,
    COMMA,
    ASSIGNMENT,
    PLUS,
    MINUS,
    MULTIPLICATION,
    DIVISION,
    LESS_THAN,
    GREATER_THAN,
    EQUALS,
    NOT_EQUALS,
    LESS_THAN_OR_EQUAL,
    GREATER_THAN_OR_EQUAL,
    // Otros tipos de tokens como operadores, constantes, etc. pueden ser agregados aquí
};

// Estructura para representar un token
struct Token {
    TokenType type;
    std::string lexeme;
};

// Analizador léxico
std::vector<Token> lexer(const std::string& sourceCode) {
    std::vector<Token> tokens;
    std::stringstream ss(sourceCode);
    std::string token;
    while (ss >> token) {
        if (token == "if") {
            tokens.push_back({TokenType::IF, token});
        } else if (token == "else") {
            tokens.push_back({TokenType::ELSE, token});
        } else if (token == "switch") {
            tokens.push_back({TokenType::SWITCH, token});
        } else if (token == "case") {
            tokens.push_back({TokenType::CASE, token});
        } else if (token == "default") {
            tokens.push_back({TokenType::DEFAULT, token});
        } else if (token == "for") {
            tokens.push_back({TokenType::FOR, token});
        } else if (token == "while") {
            tokens.push_back({TokenType::WHILE, token});
        } else if (token == "int" || token == "float" || token == "double" || token == "char") {
            tokens.push_back({TokenType::VARIABLE, token});
        } else if (token[token.length() - 1] == ';') {
            tokens.push_back({TokenType::SEMICOLON, token});
        } else if (token == "{") {
            tokens.push_back({TokenType::OPEN_BRACE, token});
        } else if (token == "}") {
            tokens.push_back({TokenType::CLOSE_BRACE, token});
        } else if (token == "(") {
            tokens.push_back({TokenType::OPEN_PAREN, token});
        } else if (token == ")") {
            tokens.push_back({TokenType::CLOSE_PAREN, token});
        } else if (token == ",") {
            tokens.push_back({TokenType::COMMA, token});
        } else if (token == "=") {
            tokens.push_back({TokenType::ASSIGNMENT, token});
        } else if (token == "+") {
            tokens.push_back({TokenType::PLUS, token});
        } else if (token == "-") {
            tokens.push_back({TokenType::MINUS, token});
        } else if (token == "*") {
            tokens.push_back({TokenType::MULTIPLICATION, token});
        } else if (token == "/") {
            tokens.push_back({TokenType::DIVISION, token});
        } else if (token == "<") {
            tokens.push_back({TokenType::LESS_THAN, token});
        } else if (token == ">") {
            tokens.push_back({TokenType::GREATER_THAN, token});
        } else if (token == "==") {
            tokens.push_back({TokenType::EQUALS, token});
        } else if (token == "!=") {
            tokens.push_back({TokenType::NOT_EQUALS, token});
        } else if (token == "<=") {
            tokens.push_back({TokenType::LESS_THAN_OR_EQUAL, token});
        } else if (token == ">=") {
            tokens.push_back({TokenType::GREATER_THAN_OR_EQUAL, token});
        } else {
            // Si no coincide con ninguna palabra clave ni con operadores, asumimos que es un identificador
            tokens.push_back({TokenType::IDENTIFIER, token});
        }
    }
    return tokens;
}

// Tabla de símbolos para mantener un registro de variables y funciones
std::unordered_map<std::string, TokenType> symbolTable;

// Analizador sintáctico
void parser(const std::vector<Token>& tokens) {
    bool insideFunction = false; // Bandera para seguir si estamos dentro de la declaración de una función
    bool expectingSemicolon = false; // Bandera para verificar si se espera un punto y coma
    for (size_t i = 0; i < tokens.size(); ++i) {
        const Token& token = tokens[i];
        switch (token.type) {
            case TokenType::IF:
                std::cout << "Se encontró una sentencia 'if'\n";
                break;
            case TokenType::ELSE:
                std::cout << "Se encontró una sentencia 'else'\n";
                break;
            case TokenType::SWITCH:
                std::cout << "Se encontró una sentencia 'switch'\n";
                break;
            case TokenType::CASE:
                std::cout << "Se encontró una sentencia 'case'\n";
                break;
            case TokenType::DEFAULT:
                std::cout << "Se encontró una sentencia 'default'\n";
                break;
            case TokenType::FOR:
                std::cout << "Se encontró una sentencia 'for'\n";
                break;
            case TokenType::WHILE:
                std::cout << "Se encontró una sentencia 'while'\n";
                break;
            case TokenType::FUNCTION:
                std::cout << "Se encontró una declaración de función: " << tokens[i + 1].lexeme << '\n';
                insideFunction = true; // Marcamos que estamos dentro de una función
                expectingSemicolon = false; // Reseteamos la bandera para el punto y coma
                break;
            case TokenType::VARIABLE:
                if (!insideFunction) {
                    std::cout << "Se encontró una declaración de variable: " << tokens[i + 1].lexeme << '\n';
                    expectingSemicolon = true; // Marcamos que esperamos un punto y coma
                }
                break;
            case TokenType::SEMICOLON:
                if (expectingSemicolon) {
                    std::cout << "Se encontró un punto y coma\n";
                    expectingSemicolon = false; // Reseteamos la bandera
                }
                break;
            // Aquí puedes agregar casos para otros tipos de tokens como OPEN_BRACE, CLOSE_BRACE, etc.
            default:
                break;
        }
    }
}

int main() {
    std::string sourceCode = "int main() { int x = 5; for (int i = 0; i < 10; i++) { x += i; } }";
    std::vector<Token> tokens = lexer(sourceCode);
    
    // Agregar variables y funciones a la tabla de símbolos (por ahora solo de ejemplo)
    symbolTable["int"] = TokenType::VARIABLE;
    symbolTable["float"] = TokenType::VARIABLE;
    symbolTable["double"] = TokenType::VARIABLE;
    symbolTable["char"] = TokenType::VARIABLE;
    symbolTable["main"] = TokenType::FUNCTION;
    
    parser(tokens);
    
    return 0;
}
