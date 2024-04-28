#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

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
    // Lógica para analizar el código fuente y generar tokens
    // Aquí solo hay un ejemplo simple
    // Debes implementar la lógica completa del analizador léxico
    // y definir las palabras clave, identificadores, etc.
    // Aquí solo se generan algunos tokens de ejemplo
    tokens.push_back({TokenType::IF, "if"});
    tokens.push_back({TokenType::OPEN_PAREN, "("});
    tokens.push_back({TokenType::IDENTIFIER, "x"});
    tokens.push_back({TokenType::GREATER_THAN, ">"});
    tokens.push_back({TokenType::IDENTIFIER, "y"});
    tokens.push_back({TokenType::CLOSE_PAREN, ")"});
    tokens.push_back({TokenType::OPEN_BRACE, "{"});
    tokens.push_back({TokenType::VARIABLE, "int"});
    tokens.push_back({TokenType::IDENTIFIER, "z"});
    tokens.push_back({TokenType::ASSIGNMENT, "="});
    tokens.push_back({TokenType::IDENTIFIER, "x"});
    tokens.push_back({TokenType::PLUS, "+"});
    tokens.push_back({TokenType::IDENTIFIER, "y"});
    tokens.push_back({TokenType::SEMICOLON, ";"});
    tokens.push_back({TokenType::CLOSE_BRACE, "}"});
    // ...
    return tokens;
}

// Tabla de símbolos para mantener un registro de variables y funciones
std::unordered_map<std::string, TokenType> symbolTable;

// Analizador sintáctico
void parser(const std::vector<Token>& tokens) {
    // Lógica para analizar los tokens y construir el árbol sintáctico
    // Debes implementar la lógica completa del analizador sintáctico
    // Aquí solo se proporciona un ejemplo simple
    for (size_t i = 0; i < tokens.size(); ++i) {
        const Token& token = tokens[i];
        switch (token.type) {
            case TokenType::IF:
                std::cout << "Se encontró una sentencia 'if'\n";
                break;
            case TokenType::IDENTIFIER:
                // Comprobar si es una variable o una función
                if (symbolTable[token.lexeme] == TokenType::VARIABLE) {
                    std::cout << "Se encontró una declaración de variable: " << token.lexeme << '\n';
                } else if (symbolTable[token.lexeme] == TokenType::FUNCTION) {
                    std::cout << "Se encontró una declaración de función: " << token.lexeme << '\n';
                }
                break;
            // Agregar casos para otros tipos de tokens como SWITCH, FOR, WHILE, etc.
            default:
                break;
        }
    }
}

int main() {
    std::string sourceCode = "if (x > y) { int z = x + y; }";
    std::vector<Token> tokens = lexer(sourceCode);
    
    // Agregar variables y funciones a la tabla de símbolos (por ahora solo de ejemplo)
    symbolTable["x"] = TokenType::VARIABLE;
    symbolTable["y"] = TokenType::VARIABLE;
    symbolTable["z"] = TokenType::VARIABLE;
    symbolTable["foo"] = TokenType::FUNCTION;
    
    parser(tokens);
    
    return 0;
}
