DJOLetters::DJOLetters(CRGB color) {
  _color = color;
  _step = 0;
}

// Aanknopje 0-26
// D buiten 27-50
// D binnen 51-67
// J 68-90
// O 91-126
void DJOLetters::update() {
  if ((_lastUpdate == 0) || ((millis() - _lastUpdate) > 500)) {
    _lastUpdate = millis();
    switch(_step) {
      case 0: fillLetter(0, 26); break;
      case 1: fillLetter(27, 67); break;
      case 2: fillLetter(68, 90); break;
      case 3: fillLetter(91, 126); break;
    }
    _step++;
  }
}

void DJOLetters::fillLetter(int from, int to) {
  for(int i = from; i <= to; i++) {
    djo_leds[i] = _color;
  }
}

bool DJOLetters::finished() {
  return _step >= 5;
}

