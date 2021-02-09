## seekg()
- Sets the position of the next character to be extracted from the input stream.
```c
istream& seekg (streamoff off, ios_base::seekdir way);
                                  |- ios_base::beg	beginning of the stream
                                  |- ios_base::cur	current position in the stream
                                  |- ios_base::end	end of the stream
```
## tellg
- Returns the position of the current character in the input stream.
```c
streampos tellg();
```
## streampos
- Position inside narrow-oriented streams.
```c
typedef fpos<mbstate_t> streampos;
```
