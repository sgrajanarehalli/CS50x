<div>
    <table class="table table-striped" style="margin-left:auto; margin-right:auto; text-align:left">
     <thead>   
        <tr>
        <th style="width:200px">Symbol</th>
        <th style="width:200px">Shares Owned</th>
        <th style="width:200px">Current Price</th>
        </tr>
    </thead>
    
<tbody>
<?php foreach ($positions as $position): ?>

        <tr>
        <td style="width:200px"><?= $position["symbol"] ?></td>
        <td style="width:200px"><?= $position["shares"] ?></td>
        <td style="width:200px">$<?= $position["price"] ?></td>
        </tr>

<?php endforeach ?>
</tbody>
</table>
</div>
<div><h3> Cash Available:</h3></div>
<div><h3>$<?= $cash ?></h3></div>
