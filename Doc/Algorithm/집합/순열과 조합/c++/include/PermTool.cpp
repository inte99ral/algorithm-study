#include "PermTool.hpp"

// Implements Definition ====================
// PermTool ============================
int PermTool::factorial(int x) { return (x == 1) || (x == 0) ? 1 : x * factorial(x - 1); }
