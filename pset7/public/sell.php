<?php

    // configuration
    require("../includes/config.php"); 

    $rows=CS50::query("SELECT * FROM portfolios WHERE user_id={$_SESSION["id"]}");
 
    $positions = [];
    foreach ($rows as $row)
    {

        $positions[] = [
            "symbol" => $row["symbol"]
        ];
    
    }
    
    $cash_rows=CS50::query("SELECT cash FROM users WHERE id={$_SESSION["id"]}");
    $cash= $cash_rows[0]["cash"];
    
       // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
         // render portfolio
         render("sell_form.php",["positions" => $positions, "cash"=>$cash, "title" => "Sell"]);
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $symbol=$_POST["symbol"];
        $share_rows=CS50::query("SELECT shares FROM portfolios WHERE user_id=? AND symbol=?", $_SESSION["id"],$symbol);
        $shares=$share_rows[0]["shares"];
        $stock=lookup($symbol);
        $price= $stock["price"];
        $quantity=$_POST["quantity"];
        
        $revenue= $price*$quantity;
        
        if ($quantity>$shares)
        {
            apologize("Quantity exceeds number of shares owned.");
        }
        else
        {
            CS50::query("UPDATE portfolios SET shares=shares- ? WHERE user_id = ? AND symbol=?", $quantity, $_SESSION["id"], $symbol);
            if ($shares==$quantity)
            {
                CS50::query("DELETE FROM portfolios WHERE user_id = ? AND symbol = ?",$_SESSION["id"], $symbol);
            }
            CS50::query("UPDATE users SET cash= cash+ ? WHERE id=?", $revenue, $_SESSION["id"]);
            CS50::query("INSERT INTO history (user_id,Transaction,Stock,Shares,Price) VALUES(?,'SELL',?,?,?)",$_SESSION["id"], $symbol, $quantity, $price);
            render("sell_result.php", ["revenue"=>$revenue]);
        }
    }
?>
