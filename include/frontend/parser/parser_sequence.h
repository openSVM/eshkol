/**
 * @file parser_sequence.h
 * @brief Sequence special form parsing for the Eshkol parser
 * 
 * This file defines functions for parsing sequence special forms in the Eshkol parser.
 */

#ifndef ESHKOL_PARSER_SEQUENCE_H
#define ESHKOL_PARSER_SEQUENCE_H

#include "frontend/parser/parser_core.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Parse a begin special form
 * 
 * @param parser The parser
 * @param line Line number
 * @param column Column number
 * @return Begin node, or NULL on failure
 */
AstNode* parser_parse_begin(Parser* parser, size_t line, size_t column);

/**
 * @brief Parse a do special form
 * 
 * @param parser The parser
 * @param line Line number
 * @param column Column number
 * @return Do node, or NULL on failure
 */
AstNode* parser_parse_do(Parser* parser, size_t line, size_t column);

#ifdef __cplusplus
}
#endif

#endif /* ESHKOL_PARSER_SEQUENCE_H */
