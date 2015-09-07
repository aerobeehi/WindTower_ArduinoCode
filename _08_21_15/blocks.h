

class Block 
{
  protected:
    CRGB* leds = NULL;
    int firstLED = 0;
    int lastLED = 0;
    int blockSize = 0;
    Block* nextBlock = NULL;
    Block* prevBlock = NULL;

  public:
    Block() {}
    Block(CRGB* leds, int firstLED, int lastLED)
    {
      this->leds = leds;
      setFirst(firstLED);
      setLast(lastLED);
    }
    Block(CRGB* leds, int firstLED, int lastLED,
          Block* nextBlock, Block* prevBlock)
    {
      this->leds = leds;
      setFirst(firstLED);
      setLast(lastLED);
      setNext(nextBlock);
      setPrev(prevBlock);
    }

    void setLast(int lastLED) { this->lastLED = lastLED; }
    int getLast() { return lastLED; }
    void setFirst(int firstLED) { this->firstLED = firstLED; }
    int geFirst() { return firstLED; }
    void setPrev(Block* prevBlock) { this->prevBlock = prevBlock; }
    Block* getPrev() const { return prevBlock; }
    void setNext(Block* nextBlock) { this->nextBlock = nextBlock; }
    Block* getNext() const { return nextBlock; }


    void turnOn()
    {
      for (int i = firstLED; i <= lastLED; i++)
      {
        leds[i] = CRGB::Red;
      }
      FastLED.show();
    }

    void turnOff()
    {
      for (int i = firstLED; i <= lastLED; i++)
      {
        leds[i] = CRGB::Black;
      }
      FastLED.show();
    }

};
