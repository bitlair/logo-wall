Snake::Snake(CRGB color, int speed, CRGB *data, int numLeds) {
  _color = color;
  _step = 0;
  _lastUpdate = 0;
  _numLeds = numLeds;
  _data = data;
  _speed = speed;
}

void Snake::update() {
  if ((_lastUpdate == 0) || ((millis() - _lastUpdate) > _speed)) {
    _lastUpdate = millis();
    
    if (_step <= _numLeds) {
      for(int i = 0; i < _step; i++) {
        _data[i] = _color;
      }
    }

    _step++;
  }
}

bool Snake::finished() {
  return _step >= _numLeds + 20;
}

