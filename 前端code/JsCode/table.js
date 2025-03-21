//新增数据函数
function addRow(){
    var table = document.getElementById("table");
    //alert(table);
    //获取插入位置，按数组下标显示，2
    var length = table.rows.length;         
    //插入行节点
    var newRow = table.insertRow(length);   
    //插入列节点
    var nameCol = newRow.insertCell(0);
    var phonegCol = newRow.insertCell(1);
    var actionCol = newRow.insertCell(2);   
    //节点文本内容
    nameCol.innerHTML = "未命名";
    phonegCol.innerHTML = "无联系方式";
    actionCol.innerHTML = "<button onclick='deleteRow(this)'>删除</button><button onclick='editRow(this)'>修改</button>";
}
//删除数据函数
function deleteRow(button){
    //alert(button);
    var row = button.parentNode.parentNode; //获取父父节点，td，tr
    row.parentNode.removeChild(row);    
}
//修改数据函数
function editRow(button){
    var row = button.parentNode.parentNode;
    var name = row.cells[0];
    var phone = row.cells[1];

    var inputName = prompt("请输入名字:")
    var inputPhone = prompt("请输入联系方式:")
    name.innerHTML = inputName;
    phone.innerHTML = inputPhone;
}