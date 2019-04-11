//%% NEW FILE Vote BEGINS HERE %%


/*PLEASE DO NOT EDIT THIS CODE*/
/*This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language!*/

class Vote
{

  //------------------------
  // MEMBER VARIABLES
  //------------------------

  //Vote State Machines
  private static $StateNoVote = 1;
  private static $StateVoted = 2;
  private $state;

  //------------------------
  // CONSTRUCTOR
  //------------------------

  public function __construct()
  {
    $this->setState(self::$StateNoVote);
  }

  //------------------------
  // INTERFACE
  //------------------------

  public function getStateFullName()
  {
    $answer = $this->getState();
    return $answer;
  }

  public function getState()
  {
    if ($this->state == self::$StateNoVote) { return "StateNoVote"; }
    elseif ($this->state == self::$StateVoted) { return "StateVoted"; }
    return null;
  }

  public function newVote()
  {
    $wasEventProcessed = false;
    
    $aState = $this->state;
    if ($aState == self::$StateNoVote)
    {
      $this->setState(self::$StateVoted);
      $wasEventProcessed = true;
    }
    return $wasEventProcessed;
  }

  public function reVote()
  {
    $wasEventProcessed = false;
    
    $aState = $this->state;
    if ($aState == self::$StateVoted)
    {
      $this->setState(self::$StateVoted);
      $wasEventProcessed = true;
    }
    return $wasEventProcessed;
  }

  private function setState($aState)
  {
    $this->state = $aState;
  }

  public function equals($compareTo)
  {
    return $this == $compareTo;
  }

  public function delete()
  {}

}




//%% NEW FILE Statistics BEGINS HERE %%


/*PLEASE DO NOT EDIT THIS CODE*/
/*This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language!*/

class Statistics
{

  //------------------------
  // MEMBER VARIABLES
  //------------------------

  //Statistics State Machines
  private static $StateLoggInn = 1;
  private static $StateStatistikk = 2;
  private $state;

  //------------------------
  // CONSTRUCTOR
  //------------------------

  public function __construct()
  {
    $this->setState(self::$StateLoggInn);
  }

  //------------------------
  // INTERFACE
  //------------------------

  public function getStateFullName()
  {
    $answer = $this->getState();
    return $answer;
  }

  public function getState()
  {
    if ($this->state == self::$StateLoggInn) { return "StateLoggInn"; }
    elseif ($this->state == self::$StateStatistikk) { return "StateStatistikk"; }
    return null;
  }

  public function skrivInnPassord()
  {
    $wasEventProcessed = false;
    
    $aState = $this->state;
    if ($aState == self::$StateLoggInn)
    {
      $this->setState(self::$StateStatistikk);
      $wasEventProcessed = true;
    }
    return $wasEventProcessed;
  }

  public function feilPassord()
  {
    $wasEventProcessed = false;
    
    $aState = $this->state;
    if ($aState == self::$StateLoggInn)
    {
      $this->setState(self::$StateLoggInn);
      $wasEventProcessed = true;
    }
    return $wasEventProcessed;
  }

  public function filter()
  {
    $wasEventProcessed = false;
    
    $aState = $this->state;
    if ($aState == self::$StateStatistikk)
    {
      $this->setState(self::$StateStatistikk);
      $wasEventProcessed = true;
    }
    return $wasEventProcessed;
  }

  private function setState($aState)
  {
    $this->state = $aState;
  }

  public function equals($compareTo)
  {
    return $this == $compareTo;
  }

  public function delete()
  {}

}
