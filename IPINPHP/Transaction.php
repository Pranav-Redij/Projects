
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
    <link rel="stylesheet" href="styleViewallcustomers.css">
    <title>Viewallcustomers</title>
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
        <h7>All Transcations</h7>
      </div>


      <table>
         <tr>
           <th>Sender</th>
           <th>Reciever</th>
           <th>Amount</th>
         </tr>
        
     <!-- php code starts from here-->   
        <?php 
  
         $con =mysqli_connect("localhost","root","dv\{2ny|^-DrPm&W","bank");
         if($con->connect_error){
           die("Connection failed:".$con->connect_error);
         }
         $sql="SELECT Sender,Reciever,Amount from trans";
         $result=$con->query($sql);

         if($result->num_rows>0){
          while($row=$result->fetch_assoc())
          {
          echo "<tr><td>".$row["Sender"]."</td><td>".$row["Reciever"]."</td><td>".$row["Amount"]."</td></tr>";
          }
         echo "</table>";
         }else{
          echo "0 result";
         }

         $con-> close();
         ?>
      </table>
</body>
</html>