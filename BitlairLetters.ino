BitlairLetters::BitlairLetters(CRGB color) {
  _color = color;
  _step = 0;
}

void BitlairLetters::update() {
  if ((_lastUpdate == 0) || ((millis() - _lastUpdate) > 150)) {
    _lastUpdate = millis();
    switch(_step) {
      case 0: fillLetter(0, 79); break; 
      case 1: fillLetter(80, 103); break; 
      case 2: fillLetter(104, 151); break; 
      case 3: fillLetter(152, 191); break; 
      case 4: fillLetter(192, 231); break; 
      case 5: fillLetter(232, 255); break; 
      case 6: fillLetter(256, 287); break; 
    }
    _step++;
  }
}

void BitlairLetters::fillLetter(int from, int to) {
  for(int i = from; i <= to; i++) {
    bitlair_leds[i] = _color;
  }
}

bool BitlairLetters::finished() {
  return _step >= 7;
}

