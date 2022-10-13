# Linux Application Layer Test FRS
  1. Create two threads that share a **64-byte data buffer**.
  2. Thread one should create random characters with a random number of
characters (**1- 50 characters** created at a time) and append them to the data
buffer. If the number of characters to insert is larger than the available buffer size,
the thread should **wait for enough space** to be available, **not drop the data**.
 3. The second thread should consume/remove a **random number of characters**
(from 0 characters to the number of available characters) and print them to any
disk log file.
  4. Implementing on a PC edition of
Linux.
  5. The application should be written in **language C** and can be built by **GCC**.