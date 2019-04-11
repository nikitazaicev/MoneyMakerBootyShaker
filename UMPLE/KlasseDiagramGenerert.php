//%% NEW FILE Stand BEGINS HERE %%


/*PLEASE DO NOT EDIT THIS CODE*/
/*This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language!*/

// Positioning
class Stand
{

  //------------------------
  // MEMBER VARIABLES
  //------------------------

  //Stand Attributes
  private $nr;
  private $totalScore;

  //Stand Associations
  private $votes;
  private $users;
  private $statistics;

  //------------------------
  // CONSTRUCTOR
  //------------------------

  public function __construct($aNr, $aTotalScore, $aStatistics)
  {
    $this->nr = $aNr;
    $this->totalScore = $aTotalScore;
    $this->votes = array();
    $this->users = array();
    $didAddStatistics = $this->setStatistics($aStatistics);
    if (!$didAddStatistics)
    {
      throw new Exception("Unable to create stand due to statistics");
    }
  }

  //------------------------
  // INTERFACE
  //------------------------

  public function setNr($aNr)
  {
    $wasSet = false;
    $this->nr = $aNr;
    $wasSet = true;
    return $wasSet;
  }

  public function setTotalScore($aTotalScore)
  {
    $wasSet = false;
    $this->totalScore = $aTotalScore;
    $wasSet = true;
    return $wasSet;
  }

  public function getNr()
  {
    return $this->nr;
  }

  public function getTotalScore()
  {
    return $this->totalScore;
  }

  public function getVote_index($index)
  {
    $aVote = $this->votes[$index];
    return $aVote;
  }

  public function getVotes()
  {
    $newVotes = $this->votes;
    return $newVotes;
  }

  public function numberOfVotes()
  {
    $number = count($this->votes);
    return $number;
  }

  public function hasVotes()
  {
    $has = $this->numberOfVotes() > 0;
    return $has;
  }

  public function indexOfVote($aVote)
  {
    $wasFound = false;
    $index = 0;
    foreach($this->votes as $vote)
    {
      if ($vote->equals($aVote))
      {
        $wasFound = true;
        break;
      }
      $index += 1;
    }
    $index = $wasFound ? $index : -1;
    return $index;
  }

  public function getUser_index($index)
  {
    $aUser = $this->users[$index];
    return $aUser;
  }

  public function getUsers()
  {
    $newUsers = $this->users;
    return $newUsers;
  }

  public function numberOfUsers()
  {
    $number = count($this->users);
    return $number;
  }

  public function hasUsers()
  {
    $has = $this->numberOfUsers() > 0;
    return $has;
  }

  public function indexOfUser($aUser)
  {
    $wasFound = false;
    $index = 0;
    foreach($this->users as $user)
    {
      if ($user->equals($aUser))
      {
        $wasFound = true;
        break;
      }
      $index += 1;
    }
    $index = $wasFound ? $index : -1;
    return $index;
  }

  public function getStatistics()
  {
    return $this->statistics;
  }

  public static function minimumNumberOfVotes()
  {
    return 0;
  }

  public function addVoteVia($aScore, $aTime, $aUser)
  {
    return new Vote($aScore, $aTime, $this, $aUser);
  }

  public function addVote($aVote)
  {
    $wasAdded = false;
    if ($this->indexOfVote($aVote) !== -1) { return false; }
    $existingStand = $aVote->getStand();
    $isNewStand = $existingStand != null && $this !== $existingStand;
    if ($isNewStand)
    {
      $aVote->setStand($this);
    }
    else
    {
      $this->votes[] = $aVote;
    }
    $wasAdded = true;
    return $wasAdded;
  }

  public function removeVote($aVote)
  {
    $wasRemoved = false;
    //Unable to remove aVote, as it must always have a stand
    if ($this !== $aVote->getStand())
    {
      unset($this->votes[$this->indexOfVote($aVote)]);
      $this->votes = array_values($this->votes);
      $wasRemoved = true;
    }
    return $wasRemoved;
  }

  public function addVoteAt($aVote, $index)
  {  
    $wasAdded = false;
    if($this->addVote($aVote))
    {
      if($index < 0 ) { $index = 0; }
      if($index > $this->numberOfVotes()) { $index = $this->numberOfVotes() - 1; }
      array_splice($this->votes, $this->indexOfVote($aVote), 1);
      array_splice($this->votes, $index, 0, array($aVote));
      $wasAdded = true;
    }
    return $wasAdded;
  }

  public function addOrMoveVoteAt($aVote, $index)
  {
    $wasAdded = false;
    if($this->indexOfVote($aVote) !== -1)
    {
      if($index < 0 ) { $index = 0; }
      if($index > $this->numberOfVotes()) { $index = $this->numberOfVotes() - 1; }
      array_splice($this->votes, $this->indexOfVote($aVote), 1);
      array_splice($this->votes, $index, 0, array($aVote));
      $wasAdded = true;
    } 
    else 
    {
      $wasAdded = $this->addVoteAt($aVote, $index);
    }
    return $wasAdded;
  }

  public static function minimumNumberOfUsers()
  {
    return 0;
  }

  public function addUserVia($aId)
  {
    return new User($aId, $this);
  }

  public function addUser($aUser)
  {
    $wasAdded = false;
    if ($this->indexOfUser($aUser) !== -1) { return false; }
    $existingStand = $aUser->getStand();
    $isNewStand = $existingStand != null && $this !== $existingStand;
    if ($isNewStand)
    {
      $aUser->setStand($this);
    }
    else
    {
      $this->users[] = $aUser;
    }
    $wasAdded = true;
    return $wasAdded;
  }

  public function removeUser($aUser)
  {
    $wasRemoved = false;
    //Unable to remove aUser, as it must always have a stand
    if ($this !== $aUser->getStand())
    {
      unset($this->users[$this->indexOfUser($aUser)]);
      $this->users = array_values($this->users);
      $wasRemoved = true;
    }
    return $wasRemoved;
  }

  public function addUserAt($aUser, $index)
  {  
    $wasAdded = false;
    if($this->addUser($aUser))
    {
      if($index < 0 ) { $index = 0; }
      if($index > $this->numberOfUsers()) { $index = $this->numberOfUsers() - 1; }
      array_splice($this->users, $this->indexOfUser($aUser), 1);
      array_splice($this->users, $index, 0, array($aUser));
      $wasAdded = true;
    }
    return $wasAdded;
  }

  public function addOrMoveUserAt($aUser, $index)
  {
    $wasAdded = false;
    if($this->indexOfUser($aUser) !== -1)
    {
      if($index < 0 ) { $index = 0; }
      if($index > $this->numberOfUsers()) { $index = $this->numberOfUsers() - 1; }
      array_splice($this->users, $this->indexOfUser($aUser), 1);
      array_splice($this->users, $index, 0, array($aUser));
      $wasAdded = true;
    } 
    else 
    {
      $wasAdded = $this->addUserAt($aUser, $index);
    }
    return $wasAdded;
  }

  public function setStatistics($aStatistics)
  {
    $wasSet = false;
    if ($aStatistics == null)
    {
      return $wasSet;
    }
    
    $existingStatistics = $this->statistics;
    $this->statistics = $aStatistics;
    if ($existingStatistics != null && $existingStatistics != $aStatistics)
    {
      $existingStatistics->removeStand($this);
    }
    $this->statistics->addStand($this);
    $wasSet = true;
    return $wasSet;
  }

  public function equals($compareTo)
  {
    return $this == $compareTo;
  }

  public function delete()
  {
    foreach ($this->votes as $aVote)
    {
      $aVote->delete();
    }
    foreach ($this->users as $aUser)
    {
      $aUser->delete();
    }
    $placeholderStatistics = $this->statistics;
    $this->statistics = null;
    $placeholderStatistics->removeStand($this);
  }

}




//%% NEW FILE Jury BEGINS HERE %%


/*PLEASE DO NOT EDIT THIS CODE*/
/*This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language!*/

class Jury extends User
{

  //------------------------
  // MEMBER VARIABLES
  //------------------------

  //Jury Associations
  private $statistics;

  //------------------------
  // CONSTRUCTOR
  //------------------------

  public function __construct($aId, $aStand, $aStatistics)
  {
    parent::__construct($aId, $aStand);
    $didAddStatistics = $this->setStatistics($aStatistics);
    if (!$didAddStatistics)
    {
      throw new Exception("Unable to create jury due to statistics");
    }
  }

  //------------------------
  // INTERFACE
  //------------------------

  public function getStatistics()
  {
    return $this->statistics;
  }

  public function setStatistics($aStatistics)
  {
    $wasSet = false;
    if ($aStatistics == null)
    {
      return $wasSet;
    }
    
    $existingStatistics = $this->statistics;
    $this->statistics = $aStatistics;
    if ($existingStatistics != null && $existingStatistics != $aStatistics)
    {
      $existingStatistics->removeJury($this);
    }
    $this->statistics->addJury($this);
    $wasSet = true;
    return $wasSet;
  }

  public function equals($compareTo)
  {
    return $this == $compareTo;
  }

  public function delete()
  {
    $placeholderStatistics = $this->statistics;
    $this->statistics = null;
    $placeholderStatistics->removeJury($this);
    parent::delete();
  }

}




//%% NEW FILE Vote BEGINS HERE %%


/*PLEASE DO NOT EDIT THIS CODE*/
/*This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language!*/

class Vote
{

  //------------------------
  // MEMBER VARIABLES
  //------------------------

  //Vote Attributes
  private $score;
  private $time;

  //Vote Associations
  private $stand;
  private $user;

  //------------------------
  // CONSTRUCTOR
  //------------------------

  public function __construct($aScore, $aTime, $aStand, $aUser)
  {
    $this->score = $aScore;
    $this->time = $aTime;
    $didAddStand = $this->setStand($aStand);
    if (!$didAddStand)
    {
      throw new Exception("Unable to create vote due to stand");
    }
    $didAddUser = $this->setUser($aUser);
    if (!$didAddUser)
    {
      throw new Exception("Unable to create vote due to user");
    }
  }

  //------------------------
  // INTERFACE
  //------------------------

  public function setScore($aScore)
  {
    $wasSet = false;
    $this->score = $aScore;
    $wasSet = true;
    return $wasSet;
  }

  public function setTime($aTime)
  {
    $wasSet = false;
    $this->time = $aTime;
    $wasSet = true;
    return $wasSet;
  }

  public function getScore()
  {
    return $this->score;
  }

  public function getTime()
  {
    return $this->time;
  }

  public function getStand()
  {
    return $this->stand;
  }

  public function getUser()
  {
    return $this->user;
  }

  public function setStand($aStand)
  {
    $wasSet = false;
    if ($aStand == null)
    {
      return $wasSet;
    }
    
    $existingStand = $this->stand;
    $this->stand = $aStand;
    if ($existingStand != null && $existingStand != $aStand)
    {
      $existingStand->removeVote($this);
    }
    $this->stand->addVote($this);
    $wasSet = true;
    return $wasSet;
  }

  public function setUser($aUser)
  {
    $wasSet = false;
    if ($aUser == null)
    {
      return $wasSet;
    }
    
    $existingUser = $this->user;
    $this->user = $aUser;
    if ($existingUser != null && $existingUser != $aUser)
    {
      $existingUser->removeVote($this);
    }
    $this->user->addVote($this);
    $wasSet = true;
    return $wasSet;
  }

  public function equals($compareTo)
  {
    return $this == $compareTo;
  }

  public function delete()
  {
    $placeholderStand = $this->stand;
    $this->stand = null;
    $placeholderStand->removeVote($this);
    $placeholderUser = $this->user;
    $this->user = null;
    $placeholderUser->removeVote($this);
  }

}




//%% NEW FILE User BEGINS HERE %%


/*PLEASE DO NOT EDIT THIS CODE*/
/*This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language!*/

class User
{

  //------------------------
  // MEMBER VARIABLES
  //------------------------

  //User Attributes
  private $id;

  //User Associations
  private $votes;
  private $stand;

  //------------------------
  // CONSTRUCTOR
  //------------------------

  public function __construct($aId, $aStand)
  {
    $this->id = $aId;
    $this->votes = array();
    $didAddStand = $this->setStand($aStand);
    if (!$didAddStand)
    {
      throw new Exception("Unable to create user due to stand");
    }
  }

  //------------------------
  // INTERFACE
  //------------------------

  public function setId($aId)
  {
    $wasSet = false;
    $this->id = $aId;
    $wasSet = true;
    return $wasSet;
  }

  public function getId()
  {
    return $this->id;
  }

  public function getVote_index($index)
  {
    $aVote = $this->votes[$index];
    return $aVote;
  }

  public function getVotes()
  {
    $newVotes = $this->votes;
    return $newVotes;
  }

  public function numberOfVotes()
  {
    $number = count($this->votes);
    return $number;
  }

  public function hasVotes()
  {
    $has = $this->numberOfVotes() > 0;
    return $has;
  }

  public function indexOfVote($aVote)
  {
    $wasFound = false;
    $index = 0;
    foreach($this->votes as $vote)
    {
      if ($vote->equals($aVote))
      {
        $wasFound = true;
        break;
      }
      $index += 1;
    }
    $index = $wasFound ? $index : -1;
    return $index;
  }

  public function getStand()
  {
    return $this->stand;
  }

  public static function minimumNumberOfVotes()
  {
    return 0;
  }

  public function addVoteVia($aScore, $aTime, $aStand)
  {
    return new Vote($aScore, $aTime, $aStand, $this);
  }

  public function addVote($aVote)
  {
    $wasAdded = false;
    if ($this->indexOfVote($aVote) !== -1) { return false; }
    if ($this->indexOfVote($aVote) !== -1) { return false; }
    $existingUser = $aVote->getUser();
    $isNewUser = $existingUser != null && $this !== $existingUser;
    if ($isNewUser)
    {
      $aVote->setUser($this);
    }
    else
    {
      $this->votes[] = $aVote;
    }
    $wasAdded = true;
    return $wasAdded;
  }

  public function removeVote($aVote)
  {
    $wasRemoved = false;
    //Unable to remove aVote, as it must always have a user
    if ($this !== $aVote->getUser())
    {
      unset($this->votes[$this->indexOfVote($aVote)]);
      $this->votes = array_values($this->votes);
      $wasRemoved = true;
    }
    return $wasRemoved;
  }

  public function addVoteAt($aVote, $index)
  {  
    $wasAdded = false;
    if($this->addVote($aVote))
    {
      if($index < 0 ) { $index = 0; }
      if($index > $this->numberOfVotes()) { $index = $this->numberOfVotes() - 1; }
      array_splice($this->votes, $this->indexOfVote($aVote), 1);
      array_splice($this->votes, $index, 0, array($aVote));
      $wasAdded = true;
    }
    return $wasAdded;
  }

  public function addOrMoveVoteAt($aVote, $index)
  {
    $wasAdded = false;
    if($this->indexOfVote($aVote) !== -1)
    {
      if($index < 0 ) { $index = 0; }
      if($index > $this->numberOfVotes()) { $index = $this->numberOfVotes() - 1; }
      array_splice($this->votes, $this->indexOfVote($aVote), 1);
      array_splice($this->votes, $index, 0, array($aVote));
      $wasAdded = true;
    } 
    else 
    {
      $wasAdded = $this->addVoteAt($aVote, $index);
    }
    return $wasAdded;
  }

  public function setStand($aStand)
  {
    $wasSet = false;
    if ($aStand == null)
    {
      return $wasSet;
    }
    
    $existingStand = $this->stand;
    $this->stand = $aStand;
    if ($existingStand != null && $existingStand != $aStand)
    {
      $existingStand->removeUser($this);
    }
    $this->stand->addUser($this);
    $wasSet = true;
    return $wasSet;
  }

  public function equals($compareTo)
  {
    return $this == $compareTo;
  }

  public function delete()
  {
    foreach ($this->votes as $aVote)
    {
      $aVote->delete();
    }
    $placeholderStand = $this->stand;
    $this->stand = null;
    $placeholderStand->removeUser($this);
  }

}




//%% NEW FILE Statistics BEGINS HERE %%


/*PLEASE DO NOT EDIT THIS CODE*/
/*This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language!*/

class Statistics
{

  //------------------------
  // MEMBER VARIABLES
  //------------------------

  //Statistics Attributes
  private $password;

  //Statistics Associations
  private $stands;
  private $juries;

  //------------------------
  // CONSTRUCTOR
  //------------------------

  public function __construct($aPassword)
  {
    $this->password = $aPassword;
    $this->stands = array();
    $this->juries = array();
  }

  //------------------------
  // INTERFACE
  //------------------------

  public function setPassword($aPassword)
  {
    $wasSet = false;
    $this->password = $aPassword;
    $wasSet = true;
    return $wasSet;
  }

  public function getPassword()
  {
    return $this->password;
  }

  public function getStand_index($index)
  {
    $aStand = $this->stands[$index];
    return $aStand;
  }

  public function getStands()
  {
    $newStands = $this->stands;
    return $newStands;
  }

  public function numberOfStands()
  {
    $number = count($this->stands);
    return $number;
  }

  public function hasStands()
  {
    $has = $this->numberOfStands() > 0;
    return $has;
  }

  public function indexOfStand($aStand)
  {
    $wasFound = false;
    $index = 0;
    foreach($this->stands as $stand)
    {
      if ($stand->equals($aStand))
      {
        $wasFound = true;
        break;
      }
      $index += 1;
    }
    $index = $wasFound ? $index : -1;
    return $index;
  }

  public function getJury_index($index)
  {
    $aJury = $this->juries[$index];
    return $aJury;
  }

  public function getJuries()
  {
    $newJuries = $this->juries;
    return $newJuries;
  }

  public function numberOfJuries()
  {
    $number = count($this->juries);
    return $number;
  }

  public function hasJuries()
  {
    $has = $this->numberOfJuries() > 0;
    return $has;
  }

  public function indexOfJury($aJury)
  {
    $wasFound = false;
    $index = 0;
    foreach($this->juries as $jury)
    {
      if ($jury->equals($aJury))
      {
        $wasFound = true;
        break;
      }
      $index += 1;
    }
    $index = $wasFound ? $index : -1;
    return $index;
  }

  public static function minimumNumberOfStands()
  {
    return 0;
  }

  public function addStandVia($aNr, $aTotalScore)
  {
    return new Stand($aNr, $aTotalScore, $this);
  }

  public function addStand($aStand)
  {
    $wasAdded = false;
    if ($this->indexOfStand($aStand) !== -1) { return false; }
    $existingStatistics = $aStand->getStatistics();
    $isNewStatistics = $existingStatistics != null && $this !== $existingStatistics;
    if ($isNewStatistics)
    {
      $aStand->setStatistics($this);
    }
    else
    {
      $this->stands[] = $aStand;
    }
    $wasAdded = true;
    return $wasAdded;
  }

  public function removeStand($aStand)
  {
    $wasRemoved = false;
    //Unable to remove aStand, as it must always have a statistics
    if ($this !== $aStand->getStatistics())
    {
      unset($this->stands[$this->indexOfStand($aStand)]);
      $this->stands = array_values($this->stands);
      $wasRemoved = true;
    }
    return $wasRemoved;
  }

  public function addStandAt($aStand, $index)
  {  
    $wasAdded = false;
    if($this->addStand($aStand))
    {
      if($index < 0 ) { $index = 0; }
      if($index > $this->numberOfStands()) { $index = $this->numberOfStands() - 1; }
      array_splice($this->stands, $this->indexOfStand($aStand), 1);
      array_splice($this->stands, $index, 0, array($aStand));
      $wasAdded = true;
    }
    return $wasAdded;
  }

  public function addOrMoveStandAt($aStand, $index)
  {
    $wasAdded = false;
    if($this->indexOfStand($aStand) !== -1)
    {
      if($index < 0 ) { $index = 0; }
      if($index > $this->numberOfStands()) { $index = $this->numberOfStands() - 1; }
      array_splice($this->stands, $this->indexOfStand($aStand), 1);
      array_splice($this->stands, $index, 0, array($aStand));
      $wasAdded = true;
    } 
    else 
    {
      $wasAdded = $this->addStandAt($aStand, $index);
    }
    return $wasAdded;
  }

  public static function minimumNumberOfJuries()
  {
    return 0;
  }

  public function addJuryVia($aId, $aStand)
  {
    return new Jury($aId, $aStand, $this);
  }

  public function addJury($aJury)
  {
    $wasAdded = false;
    if ($this->indexOfJury($aJury) !== -1) { return false; }
    $existingStatistics = $aJury->getStatistics();
    $isNewStatistics = $existingStatistics != null && $this !== $existingStatistics;
    if ($isNewStatistics)
    {
      $aJury->setStatistics($this);
    }
    else
    {
      $this->juries[] = $aJury;
    }
    $wasAdded = true;
    return $wasAdded;
  }

  public function removeJury($aJury)
  {
    $wasRemoved = false;
    //Unable to remove aJury, as it must always have a statistics
    if ($this !== $aJury->getStatistics())
    {
      unset($this->juries[$this->indexOfJury($aJury)]);
      $this->juries = array_values($this->juries);
      $wasRemoved = true;
    }
    return $wasRemoved;
  }

  public function addJuryAt($aJury, $index)
  {  
    $wasAdded = false;
    if($this->addJury($aJury))
    {
      if($index < 0 ) { $index = 0; }
      if($index > $this->numberOfJuries()) { $index = $this->numberOfJuries() - 1; }
      array_splice($this->juries, $this->indexOfJury($aJury), 1);
      array_splice($this->juries, $index, 0, array($aJury));
      $wasAdded = true;
    }
    return $wasAdded;
  }

  public function addOrMoveJuryAt($aJury, $index)
  {
    $wasAdded = false;
    if($this->indexOfJury($aJury) !== -1)
    {
      if($index < 0 ) { $index = 0; }
      if($index > $this->numberOfJuries()) { $index = $this->numberOfJuries() - 1; }
      array_splice($this->juries, $this->indexOfJury($aJury), 1);
      array_splice($this->juries, $index, 0, array($aJury));
      $wasAdded = true;
    } 
    else 
    {
      $wasAdded = $this->addJuryAt($aJury, $index);
    }
    return $wasAdded;
  }

  public function equals($compareTo)
  {
    return $this == $compareTo;
  }

  public function delete()
  {
    foreach ($this->stands as $aStand)
    {
      $aStand->delete();
    }
    foreach ($this->juries as $aJury)
    {
      $aJury->delete();
    }
  }

}
