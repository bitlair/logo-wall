BitlairScrollUp::BitlairScrollUp(CRGB color) {
  _color = color;
  _step = 0;
  _lastUpdate = 0;
}

void BitlairScrollUp::update() {
  if ((_lastUpdate == 0) || ((millis() - _lastUpdate) > 100)) {
    _lastUpdate = millis();
    if (_step <= ROWS) {
      for(int y = 0; y < _step; y++) {
        for(int x = 0; x < COLUMNS; x++) {
          int pos = bitlair_grid[ROWS - 1 - y][x];
          if (pos != -1) bitlair_leds[pos] = _color;
        }
      }
    }

    _step++;
  }

}

bool BitlairScrollUp::finished() {
  return _step >= (ROWS + 20);
}

