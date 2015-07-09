# MyanmarParser-C
This is the C version of https://github.com/thanlwinsoft/MyanmarParser

## Usage

```C
const uint16 *text = "myanmar text"
int offset = 0;
while (1) {
  int breakType;
  int next_offset = get_next_syllable(text, (int)string.length, offset, &breakType);
  offset = next_offset;
  if (breakType == MY_PAIR_EOL) {
    break;
  }
}
```
