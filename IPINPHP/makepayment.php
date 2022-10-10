<!DOCTYPE html>
<html lang="en">
<head>
     <!-- CSS only -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-iYQeCzEYFbKjA/T2uDLTpkwGzCiq6soy8tYaI1GyVh/UjpbCx/TYkiZhlZB6+fzT" crossorigin="anonymous">
    <!-- JavaScript Bundle with Popper -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-u1OknCvxWvY5kfmNBILK2hRnQC3Pr17a+RTT6rIHI7NnikvbZlHgTPOOmMi466C8" crossorigin="anonymous"></script>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="stylemakepayment.css">
    <title>Transfermoney</title>
</head>
<body>
<nav class="navbar navbar-dark bg-dark fixed-top">
    <div class="container-fluid">
      <a class="navbar-brand" href="#" style="font-size: 30px;" >Spårk B@ñk</a>
      <button class="navbar-toggler" type="button" data-bs-toggle="offcanvas" data-bs-target="#offcanvasDarkNavbar" aria-controls="offcanvasDarkNavbar">
        <span class="navbar-toggler-icon"></span>
      </button>
      <div class="offcanvas offcanvas-end text-bg-dark" tabindex="-1" id="offcanvasDarkNavbar" aria-labelledby="offcanvasDarkNavbarLabel">
        <div class="offcanvas-header">
          <h5 class="offcanvas-title" id="offcanvasDarkNavbarLabel" style="font-size: 30px;">Welcome</h5>
          <button type="button" class="btn-close btn-close-white" data-bs-dismiss="offcanvas" aria-label="Close"></button>
        </div>
        <div class="offcanvas-body">
          <ul class="navbar-nav justify-content-end flex-grow-1 pe-3">
            <li class="nav-item">
              <a class="nav-link active" aria-current="page" href="index.php" style="font-size: 20px;">Home</a>
            </li>
            <li class="nav-item">
                <a class="nav-link active" aria-current="page" href="makepayment.php" style="font-size: 20px;">Make Payment</a>
              </li>
              <li class="nav-item">
                <a class="nav-link active" aria-current="page" href="Transaction.php" style="font-size: 20px;">Transactions</a>
              </li>
              <li class="nav-item">
                <a class="nav-link active" aria-current="page" href="Viewallcustomers.php" style="font-size: 20px;">View All Customers</a>
              </li>
          </ul>
        </div>
      </div>
    </div>
  </nav>
    

      <div class="mainbody">
      <h6 style="   font-size: 40px;color: white; align-items: center; position: fixed; ">TRANSFER MONEY</h6>
      </div>
      <div class="formarea">
       <form action="makepayment.php" method="get">
          <input type="int" name="sender_ac_no" id="sender_ac_no" placeholder="Enters Senders Account No.">
          <input type="int" name="reciever_ac_no" id="reciever_ac_no" placeholder="Enters Recievers Account No.">
          <input type="int" name="amount" id="amount" placeholder="Enters Amount To Send">
          <button class="btn">Send</button>
        </form>
       </div>
       
       <!-- php code-->
     <?php
    //making code for transcation page
    $con =mysqli_connect("localhost","root","dv\{2ny|^-DrPm&W","bank");
    if($con->connect_error){
      die("Connection failed:".$con->connect_error);
    }
   //$db=mysqli_select_db($con,'user');

    $sacno=$_GET['sender_ac_no'];
    $racno=$_GET['reciever_ac_no'];
    $amount=$_GET['amount'];//amount to send from sender
   // echo $amount;
   //insert data inside transcation database
   $sql="INSERT INTO trans(Sender,Reciever,Amount)
          VALUES($sacno,$racno,$amount)";
          if($con->query($sql)===true)
          {
            //data inserted
          }else{
            echo "error:".$sql."<br>".$con->error;
          }
   


    //rest from here is same as previous
       $con =mysqli_connect("localhost","root","dv\{2ny|^-DrPm&W","bank");
       if($con->connect_error){
         die("Connection failed:".$con->connect_error);
       }
      //$db=mysqli_select_db($con,'user');

       $sacno=$_GET['sender_ac_no'];
       $racno=$_GET['reciever_ac_no'];
       $amount=$_GET['amount'];//amount to send from sender
      // echo $amount;
       //fectching sender account data from there account no.
       //echo $sacno;
     
     
        
        //using display vala fuction to store using if condition
        $con =mysqli_connect("localhost","root","dv\{2ny|^-DrPm&W","bank");
        if($con->connect_error){
          die("Connection failed:".$con->connect_error);
        }
        $sql="SELECT name,acno,balance from user";
        $result=$con->query($sql);

        if($result->num_rows>0){
         while($row=$result->fetch_assoc())
         {
           if($row["acno"]==$sacno)
           {
            $sbalance=$row["balance"];
           }
         }
       
        }else{
         echo "0 result";
        }

       // $con-> close();

      // echo $sbalance;
         //echo "The sender balance ".$sbalance; 
         //fectching reciever account data from there account no.
        
       
        
              //using display vala fuction to store using if condition
        $con =mysqli_connect("localhost","root","dv\{2ny|^-DrPm&W","bank");
        if($con->connect_error){
          die("Connection failed:".$con->connect_error);
        }
        $sql="SELECT name,acno,balance from user";
        $result=$con->query($sql);

        if($result->num_rows>0){
         while($row=$result->fetch_assoc())
         {
           if($row["acno"]==$racno)
           {
            $rbalance=$row["balance"];
           }
         }
       
        }else{
         echo "0 result";
        }

        //$con-> close();

       //echo $rbalance;
   /////////////////////////////////////////////////////////////
   $con =mysqli_connect("localhost","root","dv\{2ny|^-DrPm&W","bank");
   if($con->connect_error){
     die("Connection failed:".$con->connect_error);
   }
  //$db=mysqli_select_db($con,'user');

   $sacno=$_GET['sender_ac_no'];
   $racno=$_GET['reciever_ac_no'];
   $amount=$_GET['amount'];//amount to send from sender
  // echo $amount;
   //fectching sender account data from there account no.
   //echo $sacno;
         //senders new balance
        $snewbalance=$sbalance-$amount;

        // echo "The sum of $number1 and $number2 is: ".$snewbalance;   
         //recievers new balance
         $rnewbalance=$rbalance+$amount;

         //feeding sender new balance
         $query="UPDATE user SET balance='$snewbalance' WHERE acno='$sacno'";
         $query_run=mysqli_query($con,$query);
         //feeding recievers new balance
         $query="UPDATE user SET balance='$rnewbalance' WHERE acno='$racno'";
         $query_run=mysqli_query($con,$query);
      $con-> close();
       ?>
</body>
</html>