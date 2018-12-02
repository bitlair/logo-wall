Static::Static(CRGB color, int delay, CRGB *data, int numLeds) {
  for(int i = 0; i < numLeds; i++) { data[i] = color; }
  _waitUntil = millis() + delay;
}

void Static::update() {
}

bool Static::finished() {
  return millis() >= _waitUntil;
}

