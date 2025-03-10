// Code your testbench here
// or browse Examples
module AND_Gate_tb;
  reg A;
  reg B;
  wire Y;
  integer i;
  
  AND_Gate inst(.A(A), .B(B), .Y(Y));
  
  initial begin
    $dumpfile("dump.vcd");
    $dumpvars;
    #100 $finish;
  end
  
  initial 
    begin
      A = 0; B = 0;
      #5A = 0; B = 0;
      #5A = 1; B=0;
      #5A = 1; B=1;
    end
   
endmodule
