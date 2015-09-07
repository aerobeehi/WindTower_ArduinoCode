class Block
{
  protected:
    CRGB* leds = NULL;
    bool isFirst = false;
    int blockSize = 0;
    CRGB blockColor = CRGB::White;
    Block* nextBlock = NULL;
    Block* prevBlock = NULL;
    int firstLED = 0;
    int lastLED = 0;

  public:
    Block() {}
    
    Block(CRGB* leds, bool isFirst, int blockSize)
    {
      this->leds = leds;
      this->isFirst = isFirst;
      this->blockSize = blockSize;
    }

    Block(CRGB* leds, bool isFirst, int blockSize, CRGB blockColor)
    {
      this->leds = leds;
      this->isFirst = isFirst;
      this->blockSize = blockSize;
      this->blockColor = blockColor;
    }

    int getBlockSize() { return blockSize; }
    void setPrev(Block* prevBlock) { this->prevBlock = prevBlock; }
    Block* getPrev() const { return prevBlock; }
    void setNext(Block* nextBlock) { this->nextBlock = nextBlock; }
    Block* getNext() const { return nextBlock; }
    

    void setFirst()
    {
      if (this->isFirst == true)
      {
        this->firstLED = 0;
      }
      else
      {
        this->firstLED = (this->prevBlock->lastLED) + 1;
      }
    }
    int getFirst() { return firstLED; }

    void setLast()
    {
      if (this->isFirst == true)
      {
        this->lastLED = this->getBlockSize() - 1;
      }
      else
      {
        this->lastLED = this->getFirst() + this->getBlockSize() - 1;
      }
    }
    int getLast() { return lastLED; }



/////////////////////////////////////////////////////////
  void setSides(Block* prev, Block* next)
  {
    this->setPrev(prev);
    this->setNext(next);
    
    this->setFirst();
    this->setLast();
  }
    

    void turnOn()
    {
      for (int i = firstLED; i <= lastLED; i++)
      {
        leds[i] = blockColor;
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
