# Input stream 


## std::cin::ignore(streamsize n = 1, int delim = EOF) 

Extracts characters from the input sequence and discards them, until either `n` characters have been extracted, or one compares equal to `delim`. </br>
Essentially, for `std::cin` statements you use igonre before you do a `getline` call, because when a user inputs something with `std::cin`, they hit enter and a `\n` char gets into the `cin` buffer. Then if you use `getline`, it gets the newline char instead of the string you want. So you do a `std::cin.ignore(1000, '\n')` and that should clear the buffer up to the string that you want. 


