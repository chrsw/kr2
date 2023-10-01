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
 * Returns:
 *      Rotated integer value, unsigned.
 *
 * Design:
 *      Take the right n bits into a temporary value, shift the temporary
 *      value to the left by 32-n bits, shift the original value to the right
 *      by n bits, 'or' the temporary value and the shifted value.
 *
 * Implementation:
 *      The final compact one-liner can be broken down as follows:
 *
 *      ~0 << n
 *      Create a value of all 1's (how big is this?).
 *      Shift the value to the left by n places.
 *      This leaves a value of 1's in the high 32-n bits of the word and
 *      0's in the lower n bits part of the word.
 *
 *      ~(~0 << n)
 *      Bit-wise inversion of the previous value discussed.
 *      This leaves a value of 0's in the high 32-n bits of the word and
 *      1's in the lower n bits part of the word.
 *
 *      x & ~(~0 << n)
 *      Bit-wise and the original x with previous value discussed.
 *      This means only lower n bits of the original word remain.
 *      The higher 32-n bits of the word are cleared.
 *
 *      (x & ~(~0 << n)) << (32-n)
 *      This shifts the original lower n bits of the word to the high n
 *      bits at the other end of the word. Now the part that needed to rotate
 *      around to the other side is in place.
 *
 *      (x & ~(~0 << n)) << (32-n) | (x >> n);
 *      Finally the result is created from the value in the previous
 *      discussion or'ed with the original value shifted left n places.
 *      This means the value rotated to the other end is combined with
 *      the original value shifted to lower end of the word by n bits.
 *      The two parts of the word are re-assembled from the lower end
 *      swinging around to the higher end and the higher end shifted
 *      to the lower end.
 *
 * Build:
 *      $ gcc -o rightrot rightrot.c ex2-8_main.c
 *
 * Run:
 *      $ ./rightrot
 *
 */


unsigned int rightrot(unsigned int x, unsigned int n) {

    return (x & ~(~0 << n)) << (32-n) | (x >> n);
}
