//%% NEW FILE Stand BEGINS HERE %%

/*PLEASE DO NOT EDIT THIS CODE*/
/*This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language!*/


import java.util.*;

/**
 * Positioning
 */
// line 2 "model.ump"
// line 39 "model.ump"
public class Stand
{

  //------------------------
  // MEMBER VARIABLES
  //------------------------

  //Stand Attributes
  private String nr;
  private int totalScore;

  //Stand Associations
  private List<Vote> votes;
  private List<User> users;
  private Statistics statistics;

  //------------------------
  // CONSTRUCTOR
  //------------------------

  public Stand(String aNr, int aTotalScore, Statistics aStatistics)
  {
    nr = aNr;
    totalScore = aTotalScore;
    votes = new ArrayList<Vote>();
    users = new ArrayList<User>();
    boolean didAddStatistics = setStatistics(aStatistics);
    if (!didAddStatistics)
    {
      throw new RuntimeException("Unable to create stand due to statistics");
    }
  }

  //------------------------
  // INTERFACE
  //------------------------

  public boolean setNr(String aNr)
  {
    boolean wasSet = false;
    nr = aNr;
    wasSet = true;
    return wasSet;
  }

  public boolean setTotalScore(int aTotalScore)
  {
    boolean wasSet = false;
    totalScore = aTotalScore;
    wasSet = true;
    return wasSet;
  }

  public String getNr()
  {
    return nr;
  }

  public int getTotalScore()
  {
    return totalScore;
  }
  /* Code from template association_GetMany */
  public Vote getVote(int index)
  {
    Vote aVote = votes.get(index);
    return aVote;
  }

  public List<Vote> getVotes()
  {
    List<Vote> newVotes = Collections.unmodifiableList(votes);
    return newVotes;
  }

  public int numberOfVotes()
  {
    int number = votes.size();
    return number;
  }

  public boolean hasVotes()
  {
    boolean has = votes.size() > 0;
    return has;
  }

  public int indexOfVote(Vote aVote)
  {
    int index = votes.indexOf(aVote);
    return index;
  }
  /* Code from template association_GetMany */
  public User getUser(int index)
  {
    User aUser = users.get(index);
    return aUser;
  }

  public List<User> getUsers()
  {
    List<User> newUsers = Collections.unmodifiableList(users);
    return newUsers;
  }

  public int numberOfUsers()
  {
    int number = users.size();
    return number;
  }

  public boolean hasUsers()
  {
    boolean has = users.size() > 0;
    return has;
  }

  public int indexOfUser(User aUser)
  {
    int index = users.indexOf(aUser);
    return index;
  }
  /* Code from template association_GetOne */
  public Statistics getStatistics()
  {
    return statistics;
  }
  /* Code from template association_MinimumNumberOfMethod */
  public static int minimumNumberOfVotes()
  {
    return 0;
  }
  /* Code from template association_AddManyToOne */
  public Vote addVote(int aScore, String aTime, User aUser)
  {
    return new Vote(aScore, aTime, this, aUser);
  }

  public boolean addVote(Vote aVote)
  {
    boolean wasAdded = false;
    if (votes.contains(aVote)) { return false; }
    Stand existingStand = aVote.getStand();
    boolean isNewStand = existingStand != null && !this.equals(existingStand);
    if (isNewStand)
    {
      aVote.setStand(this);
    }
    else
    {
      votes.add(aVote);
    }
    wasAdded = true;
    return wasAdded;
  }

  public boolean removeVote(Vote aVote)
  {
    boolean wasRemoved = false;
    //Unable to remove aVote, as it must always have a stand
    if (!this.equals(aVote.getStand()))
    {
      votes.remove(aVote);
      wasRemoved = true;
    }
    return wasRemoved;
  }
  /* Code from template association_AddIndexControlFunctions */
  public boolean addVoteAt(Vote aVote, int index)
  {  
    boolean wasAdded = false;
    if(addVote(aVote))
    {
      if(index < 0 ) { index = 0; }
      if(index > numberOfVotes()) { index = numberOfVotes() - 1; }
      votes.remove(aVote);
      votes.add(index, aVote);
      wasAdded = true;
    }
    return wasAdded;
  }

  public boolean addOrMoveVoteAt(Vote aVote, int index)
  {
    boolean wasAdded = false;
    if(votes.contains(aVote))
    {
      if(index < 0 ) { index = 0; }
      if(index > numberOfVotes()) { index = numberOfVotes() - 1; }
      votes.remove(aVote);
      votes.add(index, aVote);
      wasAdded = true;
    } 
    else 
    {
      wasAdded = addVoteAt(aVote, index);
    }
    return wasAdded;
  }
  /* Code from template association_MinimumNumberOfMethod */
  public static int minimumNumberOfUsers()
  {
    return 0;
  }
  /* Code from template association_AddManyToOne */
  public User addUser(String aId)
  {
    return new User(aId, this);
  }

  public boolean addUser(User aUser)
  {
    boolean wasAdded = false;
    if (users.contains(aUser)) { return false; }
    Stand existingStand = aUser.getStand();
    boolean isNewStand = existingStand != null && !this.equals(existingStand);
    if (isNewStand)
    {
      aUser.setStand(this);
    }
    else
    {
      users.add(aUser);
    }
    wasAdded = true;
    return wasAdded;
  }

  public boolean removeUser(User aUser)
  {
    boolean wasRemoved = false;
    //Unable to remove aUser, as it must always have a stand
    if (!this.equals(aUser.getStand()))
    {
      users.remove(aUser);
      wasRemoved = true;
    }
    return wasRemoved;
  }
  /* Code from template association_AddIndexControlFunctions */
  public boolean addUserAt(User aUser, int index)
  {  
    boolean wasAdded = false;
    if(addUser(aUser))
    {
      if(index < 0 ) { index = 0; }
      if(index > numberOfUsers()) { index = numberOfUsers() - 1; }
      users.remove(aUser);
      users.add(index, aUser);
      wasAdded = true;
    }
    return wasAdded;
  }

  public boolean addOrMoveUserAt(User aUser, int index)
  {
    boolean wasAdded = false;
    if(users.contains(aUser))
    {
      if(index < 0 ) { index = 0; }
      if(index > numberOfUsers()) { index = numberOfUsers() - 1; }
      users.remove(aUser);
      users.add(index, aUser);
      wasAdded = true;
    } 
    else 
    {
      wasAdded = addUserAt(aUser, index);
    }
    return wasAdded;
  }
  /* Code from template association_SetOneToMany */
  public boolean setStatistics(Statistics aStatistics)
  {
    boolean wasSet = false;
    if (aStatistics == null)
    {
      return wasSet;
    }

    Statistics existingStatistics = statistics;
    statistics = aStatistics;
    if (existingStatistics != null && !existingStatistics.equals(aStatistics))
    {
      existingStatistics.removeStand(this);
    }
    statistics.addStand(this);
    wasSet = true;
    return wasSet;
  }

  public void delete()
  {
    for(int i=votes.size(); i > 0; i--)
    {
      Vote aVote = votes.get(i - 1);
      aVote.delete();
    }
    for(int i=users.size(); i > 0; i--)
    {
      User aUser = users.get(i - 1);
      aUser.delete();
    }
    Statistics placeholderStatistics = statistics;
    this.statistics = null;
    if(placeholderStatistics != null)
    {
      placeholderStatistics.removeStand(this);
    }
  }


  public String toString()
  {
    return super.toString() + "["+
            "nr" + ":" + getNr()+ "," +
            "totalScore" + ":" + getTotalScore()+ "]" + System.getProperties().getProperty("line.separator") +
            "  " + "statistics = "+(getStatistics()!=null?Integer.toHexString(System.identityHashCode(getStatistics())):"null");
  }
}



//%% NEW FILE Jury BEGINS HERE %%

/*PLEASE DO NOT EDIT THIS CODE*/
/*This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language!*/


import java.util.*;

// line 22 "model.ump"
// line 58 "model.ump"
public class Jury extends User
{

  //------------------------
  // MEMBER VARIABLES
  //------------------------

  //Jury Associations
  private Statistics statistics;

  //------------------------
  // CONSTRUCTOR
  //------------------------

  public Jury(String aId, Stand aStand, Statistics aStatistics)
  {
    super(aId, aStand);
    boolean didAddStatistics = setStatistics(aStatistics);
    if (!didAddStatistics)
    {
      throw new RuntimeException("Unable to create jury due to statistics");
    }
  }

  //------------------------
  // INTERFACE
  //------------------------
  /* Code from template association_GetOne */
  public Statistics getStatistics()
  {
    return statistics;
  }
  /* Code from template association_SetOneToMany */
  public boolean setStatistics(Statistics aStatistics)
  {
    boolean wasSet = false;
    if (aStatistics == null)
    {
      return wasSet;
    }

    Statistics existingStatistics = statistics;
    statistics = aStatistics;
    if (existingStatistics != null && !existingStatistics.equals(aStatistics))
    {
      existingStatistics.removeJury(this);
    }
    statistics.addJury(this);
    wasSet = true;
    return wasSet;
  }

  public void delete()
  {
    Statistics placeholderStatistics = statistics;
    this.statistics = null;
    if(placeholderStatistics != null)
    {
      placeholderStatistics.removeJury(this);
    }
    super.delete();
  }

}



//%% NEW FILE Vote BEGINS HERE %%

/*PLEASE DO NOT EDIT THIS CODE*/
/*This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language!*/



// line 10 "model.ump"
// line 47 "model.ump"
public class Vote
{

  //------------------------
  // MEMBER VARIABLES
  //------------------------

  //Vote Attributes
  private int score;
  private String time;

  //Vote Associations
  private Stand stand;
  private User user;

  //------------------------
  // CONSTRUCTOR
  //------------------------

  public Vote(int aScore, String aTime, Stand aStand, User aUser)
  {
    score = aScore;
    time = aTime;
    boolean didAddStand = setStand(aStand);
    if (!didAddStand)
    {
      throw new RuntimeException("Unable to create vote due to stand");
    }
    boolean didAddUser = setUser(aUser);
    if (!didAddUser)
    {
      throw new RuntimeException("Unable to create vote due to user");
    }
  }

  //------------------------
  // INTERFACE
  //------------------------

  public boolean setScore(int aScore)
  {
    boolean wasSet = false;
    score = aScore;
    wasSet = true;
    return wasSet;
  }

  public boolean setTime(String aTime)
  {
    boolean wasSet = false;
    time = aTime;
    wasSet = true;
    return wasSet;
  }

  public int getScore()
  {
    return score;
  }

  public String getTime()
  {
    return time;
  }
  /* Code from template association_GetOne */
  public Stand getStand()
  {
    return stand;
  }
  /* Code from template association_GetOne */
  public User getUser()
  {
    return user;
  }
  /* Code from template association_SetOneToMany */
  public boolean setStand(Stand aStand)
  {
    boolean wasSet = false;
    if (aStand == null)
    {
      return wasSet;
    }

    Stand existingStand = stand;
    stand = aStand;
    if (existingStand != null && !existingStand.equals(aStand))
    {
      existingStand.removeVote(this);
    }
    stand.addVote(this);
    wasSet = true;
    return wasSet;
  }
  /* Code from template association_SetOneToMany */
  public boolean setUser(User aUser)
  {
    boolean wasSet = false;
    if (aUser == null)
    {
      return wasSet;
    }

    User existingUser = user;
    user = aUser;
    if (existingUser != null && !existingUser.equals(aUser))
    {
      existingUser.removeVote(this);
    }
    user.addVote(this);
    wasSet = true;
    return wasSet;
  }

  public void delete()
  {
    Stand placeholderStand = stand;
    this.stand = null;
    if(placeholderStand != null)
    {
      placeholderStand.removeVote(this);
    }
    User placeholderUser = user;
    this.user = null;
    if(placeholderUser != null)
    {
      placeholderUser.removeVote(this);
    }
  }


  public String toString()
  {
    return super.toString() + "["+
            "score" + ":" + getScore()+ "," +
            "time" + ":" + getTime()+ "]" + System.getProperties().getProperty("line.separator") +
            "  " + "stand = "+(getStand()!=null?Integer.toHexString(System.identityHashCode(getStand())):"null") + System.getProperties().getProperty("line.separator") +
            "  " + "user = "+(getUser()!=null?Integer.toHexString(System.identityHashCode(getUser())):"null");
  }
}



//%% NEW FILE User BEGINS HERE %%

/*PLEASE DO NOT EDIT THIS CODE*/
/*This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language!*/


import java.util.*;

// line 16 "model.ump"
// line 52 "model.ump"
public class User
{

  //------------------------
  // MEMBER VARIABLES
  //------------------------

  //User Attributes
  private String id;

  //User Associations
  private List<Vote> votes;
  private Stand stand;

  //------------------------
  // CONSTRUCTOR
  //------------------------

  public User(String aId, Stand aStand)
  {
    id = aId;
    votes = new ArrayList<Vote>();
    boolean didAddStand = setStand(aStand);
    if (!didAddStand)
    {
      throw new RuntimeException("Unable to create user due to stand");
    }
  }

  //------------------------
  // INTERFACE
  //------------------------

  public boolean setId(String aId)
  {
    boolean wasSet = false;
    id = aId;
    wasSet = true;
    return wasSet;
  }

  public String getId()
  {
    return id;
  }
  /* Code from template association_GetMany */
  public Vote getVote(int index)
  {
    Vote aVote = votes.get(index);
    return aVote;
  }

  public List<Vote> getVotes()
  {
    List<Vote> newVotes = Collections.unmodifiableList(votes);
    return newVotes;
  }

  public int numberOfVotes()
  {
    int number = votes.size();
    return number;
  }

  public boolean hasVotes()
  {
    boolean has = votes.size() > 0;
    return has;
  }

  public int indexOfVote(Vote aVote)
  {
    int index = votes.indexOf(aVote);
    return index;
  }
  /* Code from template association_GetOne */
  public Stand getStand()
  {
    return stand;
  }
  /* Code from template association_MinimumNumberOfMethod */
  public static int minimumNumberOfVotes()
  {
    return 0;
  }
  /* Code from template association_AddManyToOne */
  public Vote addVote(int aScore, String aTime, Stand aStand)
  {
    return new Vote(aScore, aTime, aStand, this);
  }

  public boolean addVote(Vote aVote)
  {
    boolean wasAdded = false;
    if (votes.contains(aVote)) { return false; }
    User existingUser = aVote.getUser();
    boolean isNewUser = existingUser != null && !this.equals(existingUser);
    if (isNewUser)
    {
      aVote.setUser(this);
    }
    else
    {
      votes.add(aVote);
    }
    wasAdded = true;
    return wasAdded;
  }

  public boolean removeVote(Vote aVote)
  {
    boolean wasRemoved = false;
    //Unable to remove aVote, as it must always have a user
    if (!this.equals(aVote.getUser()))
    {
      votes.remove(aVote);
      wasRemoved = true;
    }
    return wasRemoved;
  }
  /* Code from template association_AddIndexControlFunctions */
  public boolean addVoteAt(Vote aVote, int index)
  {  
    boolean wasAdded = false;
    if(addVote(aVote))
    {
      if(index < 0 ) { index = 0; }
      if(index > numberOfVotes()) { index = numberOfVotes() - 1; }
      votes.remove(aVote);
      votes.add(index, aVote);
      wasAdded = true;
    }
    return wasAdded;
  }

  public boolean addOrMoveVoteAt(Vote aVote, int index)
  {
    boolean wasAdded = false;
    if(votes.contains(aVote))
    {
      if(index < 0 ) { index = 0; }
      if(index > numberOfVotes()) { index = numberOfVotes() - 1; }
      votes.remove(aVote);
      votes.add(index, aVote);
      wasAdded = true;
    } 
    else 
    {
      wasAdded = addVoteAt(aVote, index);
    }
    return wasAdded;
  }
  /* Code from template association_SetOneToMany */
  public boolean setStand(Stand aStand)
  {
    boolean wasSet = false;
    if (aStand == null)
    {
      return wasSet;
    }

    Stand existingStand = stand;
    stand = aStand;
    if (existingStand != null && !existingStand.equals(aStand))
    {
      existingStand.removeUser(this);
    }
    stand.addUser(this);
    wasSet = true;
    return wasSet;
  }

  public void delete()
  {
    for(int i=votes.size(); i > 0; i--)
    {
      Vote aVote = votes.get(i - 1);
      aVote.delete();
    }
    Stand placeholderStand = stand;
    this.stand = null;
    if(placeholderStand != null)
    {
      placeholderStand.removeUser(this);
    }
  }


  public String toString()
  {
    return super.toString() + "["+
            "id" + ":" + getId()+ "]" + System.getProperties().getProperty("line.separator") +
            "  " + "stand = "+(getStand()!=null?Integer.toHexString(System.identityHashCode(getStand())):"null");
  }
}



//%% NEW FILE Statistics BEGINS HERE %%

/*PLEASE DO NOT EDIT THIS CODE*/
/*This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language!*/


import java.util.*;

// line 28 "model.ump"
// line 65 "model.ump"
public class Statistics
{

  //------------------------
  // MEMBER VARIABLES
  //------------------------

  //Statistics Attributes
  private String password;

  //Statistics Associations
  private List<Stand> stands;
  private List<Jury> juries;

  //------------------------
  // CONSTRUCTOR
  //------------------------

  public Statistics(String aPassword)
  {
    password = aPassword;
    stands = new ArrayList<Stand>();
    juries = new ArrayList<Jury>();
  }

  //------------------------
  // INTERFACE
  //------------------------

  public boolean setPassword(String aPassword)
  {
    boolean wasSet = false;
    password = aPassword;
    wasSet = true;
    return wasSet;
  }

  public String getPassword()
  {
    return password;
  }
  /* Code from template association_GetMany */
  public Stand getStand(int index)
  {
    Stand aStand = stands.get(index);
    return aStand;
  }

  public List<Stand> getStands()
  {
    List<Stand> newStands = Collections.unmodifiableList(stands);
    return newStands;
  }

  public int numberOfStands()
  {
    int number = stands.size();
    return number;
  }

  public boolean hasStands()
  {
    boolean has = stands.size() > 0;
    return has;
  }

  public int indexOfStand(Stand aStand)
  {
    int index = stands.indexOf(aStand);
    return index;
  }
  /* Code from template association_GetMany */
  public Jury getJury(int index)
  {
    Jury aJury = juries.get(index);
    return aJury;
  }

  public List<Jury> getJuries()
  {
    List<Jury> newJuries = Collections.unmodifiableList(juries);
    return newJuries;
  }

  public int numberOfJuries()
  {
    int number = juries.size();
    return number;
  }

  public boolean hasJuries()
  {
    boolean has = juries.size() > 0;
    return has;
  }

  public int indexOfJury(Jury aJury)
  {
    int index = juries.indexOf(aJury);
    return index;
  }
  /* Code from template association_MinimumNumberOfMethod */
  public static int minimumNumberOfStands()
  {
    return 0;
  }
  /* Code from template association_AddManyToOne */
  public Stand addStand(String aNr, int aTotalScore)
  {
    return new Stand(aNr, aTotalScore, this);
  }

  public boolean addStand(Stand aStand)
  {
    boolean wasAdded = false;
    if (stands.contains(aStand)) { return false; }
    Statistics existingStatistics = aStand.getStatistics();
    boolean isNewStatistics = existingStatistics != null && !this.equals(existingStatistics);
    if (isNewStatistics)
    {
      aStand.setStatistics(this);
    }
    else
    {
      stands.add(aStand);
    }
    wasAdded = true;
    return wasAdded;
  }

  public boolean removeStand(Stand aStand)
  {
    boolean wasRemoved = false;
    //Unable to remove aStand, as it must always have a statistics
    if (!this.equals(aStand.getStatistics()))
    {
      stands.remove(aStand);
      wasRemoved = true;
    }
    return wasRemoved;
  }
  /* Code from template association_AddIndexControlFunctions */
  public boolean addStandAt(Stand aStand, int index)
  {  
    boolean wasAdded = false;
    if(addStand(aStand))
    {
      if(index < 0 ) { index = 0; }
      if(index > numberOfStands()) { index = numberOfStands() - 1; }
      stands.remove(aStand);
      stands.add(index, aStand);
      wasAdded = true;
    }
    return wasAdded;
  }

  public boolean addOrMoveStandAt(Stand aStand, int index)
  {
    boolean wasAdded = false;
    if(stands.contains(aStand))
    {
      if(index < 0 ) { index = 0; }
      if(index > numberOfStands()) { index = numberOfStands() - 1; }
      stands.remove(aStand);
      stands.add(index, aStand);
      wasAdded = true;
    } 
    else 
    {
      wasAdded = addStandAt(aStand, index);
    }
    return wasAdded;
  }
  /* Code from template association_MinimumNumberOfMethod */
  public static int minimumNumberOfJuries()
  {
    return 0;
  }
  /* Code from template association_AddManyToOne */
  public Jury addJury(String aId, Stand aStand)
  {
    return new Jury(aId, aStand, this);
  }

  public boolean addJury(Jury aJury)
  {
    boolean wasAdded = false;
    if (juries.contains(aJury)) { return false; }
    Statistics existingStatistics = aJury.getStatistics();
    boolean isNewStatistics = existingStatistics != null && !this.equals(existingStatistics);
    if (isNewStatistics)
    {
      aJury.setStatistics(this);
    }
    else
    {
      juries.add(aJury);
    }
    wasAdded = true;
    return wasAdded;
  }

  public boolean removeJury(Jury aJury)
  {
    boolean wasRemoved = false;
    //Unable to remove aJury, as it must always have a statistics
    if (!this.equals(aJury.getStatistics()))
    {
      juries.remove(aJury);
      wasRemoved = true;
    }
    return wasRemoved;
  }
  /* Code from template association_AddIndexControlFunctions */
  public boolean addJuryAt(Jury aJury, int index)
  {  
    boolean wasAdded = false;
    if(addJury(aJury))
    {
      if(index < 0 ) { index = 0; }
      if(index > numberOfJuries()) { index = numberOfJuries() - 1; }
      juries.remove(aJury);
      juries.add(index, aJury);
      wasAdded = true;
    }
    return wasAdded;
  }

  public boolean addOrMoveJuryAt(Jury aJury, int index)
  {
    boolean wasAdded = false;
    if(juries.contains(aJury))
    {
      if(index < 0 ) { index = 0; }
      if(index > numberOfJuries()) { index = numberOfJuries() - 1; }
      juries.remove(aJury);
      juries.add(index, aJury);
      wasAdded = true;
    } 
    else 
    {
      wasAdded = addJuryAt(aJury, index);
    }
    return wasAdded;
  }

  public void delete()
  {
    for(int i=stands.size(); i > 0; i--)
    {
      Stand aStand = stands.get(i - 1);
      aStand.delete();
    }
    for(int i=juries.size(); i > 0; i--)
    {
      Jury aJury = juries.get(i - 1);
      aJury.delete();
    }
  }


  public String toString()
  {
    return super.toString() + "["+
            "password" + ":" + getPassword()+ "]";
  }
}
