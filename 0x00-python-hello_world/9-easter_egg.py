#!/usr/bin/python3
import this
zen_of_python = this.s
rot13_start_marker = 'Gur Mra bs Clguba, ol Gvz Crgref'
index = zen_of_python.find(rot13_start_marker)
if index != -1:
    english_part = zen_of_python[:index].strip()
else:
    english_part = zen_of_python.strip()
normalized_text = '\n'.join(line.strip() for line in english_part.splitlines() if line.strip())
print(normalized_text, end='')
