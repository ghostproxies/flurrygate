#include <stdint.h>

struct flurrygrid_state {
  uint64_t output[4];
  uint64_t a;
  uint64_t b;
  uint64_t c;
  uint64_t d;
};

void flurrygrid(struct flurrygrid_state *s) {
  s->a = ((s->a << 25) | (s->a >> 39)) ^ s->b;
  s->b += 1111111111111111;
  s->c = ((s->c << 37) | (s->c >> 27)) + s->a;
  s->d = ((s->d << 27) | (s->d >> 37)) + s->a;
  s->output[0] = s->c + s->d;
  s->output[1] = s->b ^ s->c;
  s->output[2] = ((s->a << 33) | (s->a >> 31)) + s->c;
  s->output[3] = (s->a + s->c) ^ s->d;
}
