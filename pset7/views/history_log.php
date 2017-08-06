<div>
    <table class="table table-striped" style="margin-left:auto; margin-right:auto; text-align:left">
     <thead>
        <tr>
        <th style="width:200px">Transaction</th>
        <th style="width:200px">Time</th>
        <th style="width:200px">Stock</th>
        <th style="width:200px">Shares</th>
        <th style="width:200px">Price</th>
        </tr>
    </thead>
    
<tbody>
<?php foreach ($positions as $position): ?>

        <tr>
        <td style="width:200px"><?= $position["Transaction"] ?></td>
        <td style="width:200px"><?= $position["Time"] ?></td>
        <td style="width:200px"><?= $position["Stock"] ?></td>
        <td style="width:200px"><?= $position["Shares"] ?></td>
        <td style="width:200px">$<?=$position["Price"] ?></td>
        </tr>

<?php endforeach ?>
</tbody>
</table>