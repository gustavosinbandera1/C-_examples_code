#include <stdio.h>
#include <string.h>

struct dumb
{
   char   broiled;
   short  circuit;
   long   johns;
   double entendre;
};

size_t serialize(unsigned char *dst, const struct dumb *object)
{
   size_t i = 0;

   memcpy(&dst[i], &object->broiled, sizeof object->broiled);
   i += sizeof object->broiled;

   memcpy(&dst[i], &object->circuit, sizeof object->circuit);
   i += sizeof object->circuit;

   memcpy(&dst[i], &object->johns, sizeof object->johns);
   i += sizeof object->johns;

   memcpy(&dst[i], &object->entendre, sizeof object->entendre);
   i += sizeof object->entendre;

   return i;
}

void showbytes(const void *object, size_t size)
{
   const unsigned char *byte;
   for ( byte = object; size--; ++byte )
   {
      printf("%02X", *byte);
   }
   putchar('\n');
}

int main()
{
   int member;
   struct dumb by[sizeof member] =
   {
      { 'A', 0x1234, 0x12345678, 123.456},
   };
   unsigned char buffer [ sizeof by[0] ];
   showbytes(buffer, serialize(buffer, by));
   return 0;
}

/* my output
4134127856341277BE9F1A2FDD5E40
*/