<?php

    // configuration
    require("../includes/config.php"); 

    
    $cash_rows=CS50::query("SELECT cash FROM users WHERE id={$_SESSION["id"]}");
    $cash= $cash_rows[0]["cash"];
    
       // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
         // render portfolio
         render("buy_form.php",["cash"=>$cash, "title" => "Buy"]);
    }
    else if($_SERVER["REQUEST_METHOD"]=="POST")
    {
        $symbol=strtoupper($_POST["symbol"]);
        $quantity=$_POST["quantity"];
        if ($stock=lookup($symbol))
        {
            $cost=$stock["price"]*$quantity;
            if ($cost<$cash)
            {
            CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], $symbol, $quantity);
            CS50::query("UPDATE users SET cash= cash- ? WHERE id=?", $cost, $_SESSION["id"]);
            CS50::query("INSERT INTO history(user_id,transaction,stock,shares,price) VALUES(?,'BUY',?,?,?)",$_SESSION["id"],$symbol, $quantity, $stock["price"]);
            render("buy_result.php",["name"=>$stock["name"], "cost"=>$cost, "quantity"=>$quantity]);
            }
            else
            {
                apologize("You do not have enough money for this transaction!");
            }
            
        }
        else 
        {
        apologize("Sorry could not find stock .");
        }
    }
    