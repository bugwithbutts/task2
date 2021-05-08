#include "_text.h" 

void ch(text txt)
{
  node* cursor_line = txt->cursor->line; // строка с курсором
  int cursor_pos = txt->cursor->position; // позиция курсора в строке

  //if(new_line == NULL) {print error; return;}
  char* new_line = (char*) malloc(sizeof(char) * (MAXLINE + 1)); // память под измененную строку

  int line_len = strlen(cursor_line->contents); // длина исходной (и новой) строки
  int begin_len = line_len - cursor_pos; // кол-во элементов после курсора и в начале новой строки

  strncpy(new_line,cursor_line->contents + cursor_pos,begin_len); // копируем конец в начало
  strncpy(new_line + begin_len,cursor_line->contents,cursor_pos); // копируем начало в конец

  new_line[line_len] = '\0'; // конец строки
  strcpy(cursor_line->contents, new_line); // копируем измененную строку

  free(new_line); // очищаем память
}
