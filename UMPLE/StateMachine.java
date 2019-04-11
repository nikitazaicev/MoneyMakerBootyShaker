//%% NEW FILE Vote BEGINS HERE %%

/*PLEASE DO NOT EDIT THIS CODE*/
/*This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language!*/



// line 2 "model.ump"
// line 25 "model.ump"
public class Vote
{

  //------------------------
  // MEMBER VARIABLES
  //------------------------

  //Vote State Machines
  public enum State { noVote, voted }
  private State state;

  //------------------------
  // CONSTRUCTOR
  //------------------------

  public Vote()
  {
    setState(State.noVote);
  }

  //------------------------
  // INTERFACE
  //------------------------

  public String getStateFullName()
  {
    String answer = state.toString();
    return answer;
  }

  public State getState()
  {
    return state;
  }

  public boolean newVote()
  {
    boolean wasEventProcessed = false;
    
    State aState = state;
    switch (aState)
    {
      case noVote:
        setState(State.voted);
        wasEventProcessed = true;
        break;
      default:
        // Other states do respond to this event
    }

    return wasEventProcessed;
  }

  public boolean reVote()
  {
    boolean wasEventProcessed = false;
    
    State aState = state;
    switch (aState)
    {
      case voted:
        setState(State.voted);
        wasEventProcessed = true;
        break;
      default:
        // Other states do respond to this event
    }

    return wasEventProcessed;
  }

  private void setState(State aState)
  {
    state = aState;
  }

  public void delete()
  {}

}



//%% NEW FILE Statistics BEGINS HERE %%

/*PLEASE DO NOT EDIT THIS CODE*/
/*This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language!*/



// line 13 "model.ump"
// line 30 "model.ump"
public class Statistics
{

  //------------------------
  // MEMBER VARIABLES
  //------------------------

  //Statistics State Machines
  public enum State { loggInn, statistikk }
  private State state;

  //------------------------
  // CONSTRUCTOR
  //------------------------

  public Statistics()
  {
    setState(State.loggInn);
  }

  //------------------------
  // INTERFACE
  //------------------------

  public String getStateFullName()
  {
    String answer = state.toString();
    return answer;
  }

  public State getState()
  {
    return state;
  }

  public boolean skrivInnPassord()
  {
    boolean wasEventProcessed = false;
    
    State aState = state;
    switch (aState)
    {
      case loggInn:
        setState(State.statistikk);
        wasEventProcessed = true;
        break;
      default:
        // Other states do respond to this event
    }

    return wasEventProcessed;
  }

  public boolean feilPassord()
  {
    boolean wasEventProcessed = false;
    
    State aState = state;
    switch (aState)
    {
      case loggInn:
        setState(State.loggInn);
        wasEventProcessed = true;
        break;
      default:
        // Other states do respond to this event
    }

    return wasEventProcessed;
  }

  public boolean filter()
  {
    boolean wasEventProcessed = false;
    
    State aState = state;
    switch (aState)
    {
      case statistikk:
        setState(State.statistikk);
        wasEventProcessed = true;
        break;
      default:
        // Other states do respond to this event
    }

    return wasEventProcessed;
  }

  private void setState(State aState)
  {
    state = aState;
  }

  public void delete()
  {}

}
