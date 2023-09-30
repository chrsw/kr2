/* vim:ts=4:sw=4:et:so=10:
 *
 * rightrot.c
 *      Write a function rightrot(x,n) that returns the value of the integer
 *      x rotate to the right by n bit positions.
 *
 * Description:
 *      The rotate operation takes a value's lowest n bits and places them
 *      at the value's highest n bits, shifting all the non-n bits to the
 *      right by n bits. For example, given the original 32-bit value
 *      0x12345678
 *      the new value resulting from rotating the original 32-bit value 4
 *      bits to the right would be:
 *      0x81234567
 *      This version only operates on unsigned values.
 *
 * Input:
 *      x:      integer to rotate to the right
 *      n:      number of bit positions to rotate to the right
 *
 * Output:
 *      Rotated integer value.
 *
 * Design:
 *      Take the right n bits into a temporary value, shift the temporary
 *      value to the left by 32-n bits, shift the original value to the right
 *      by n bits, 'or' the temporary value and the shifted value.
 *
 * Build:
 *      $ gcc -o rightrot rightrot.c ex2-8_main.c
 *
 * Run:
 *      $ ./rightrot
 *
 *
 */


unsigned int rightrot(unsigned int x, unsigned int n) {

    unsigned int temp = 0;
    temp = x & ~(~0 << n);
    temp = temp << (32-n);
    x = x >> n;
    return temp | x;
}
