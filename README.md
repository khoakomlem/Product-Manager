
# Quản lí hàng hóa tại cửa hàng Bách hóa xanh

Viết chương trình quản lí quán trình nhập và bán hàng hóa tại của hàng bách hóa xanh.

### Sản phẩm

Thông tin của mỗi sản phẩm sẽ bao gồm:

- Mã sản phẩm (*Số nguyên duy nhất được tăng tự động*).
- Tên sản phẩm (không quá $256$ kí tự).
- Phân loại sản phẩm (Xem danh mục ở dưới).
- Giá sản phẩm (Không quá $10^9$ VND).
- Cân nặng sản phẩm (Không quá $10^9$ VND).
- Ngày sản xuất (Định dạng DD/MM/YYYY).
- Hạn sử dụng (Số nguyên không quá $12$).
- Nhà sản xuất (Không quá $256$ kí tự).

Một số danh mục sản phẩm được phân loại như sau:

- "GD": Sản phẩm gia dụng.
- "TP": Thực phẩm.
- "TC": Trái cây.

### Nhân viên

Thông tin của nhân viên bán sản phẩm sẽ bao gồm:

- Mã nhân viên (*Số nguyên duy nhất được tăng tự động*).
- Họ và tên nhân viên (Không quá $256$ kí tự).
- Ngày, tháng, năm sinh (Định dạng DD/MM/YYYY).
- Số CCCD của nhân viên (Đúng $12$ chữ số).
- Địa chỉ thường trú (Không quá $256$ kí tự).
- Địa chỉ mail (Không quá $256$ kí tự).
- Số điện thoại liên lạc (Đúng $10$ chữ số).
- Thời gian làm việc (*số nguyên duy nhất là số năm làm việc, nếu năm đầu tiên thì có giá trị là $0$*).

### Hóa đơn

Với mỗi khách hàng, sau khi thực hiện thanh toán sẽ in ra hóa đơn để gửi cho khách, thông tin ở trong hóa đơn sẽ bao gồm:

- Mã đơn hàng (Số nguyên duy nhất được tăng tự động).
- Thời gian mua hàng (Định dạng DD/MM/YYYY và thời gian theo giờ/phút/giây).
- Danh sách đơn hàng (Danh sách các đơn hàng).
- Tổng tiền (Số nguyên không quá $10^9$).
- Tiền thu từ khách (Số nguyên không quá $10^9$).
- Tiền trả khách (Số nguyên không quá $10^9$).
- Nhân viên thực hiện quá trình thanh toán (*Mã nhân viên*).

### Chức năng chính của chương trình

- Chức năng **Thêm nhân viên mới**: Chương trình thực hiện thêm một nhân viên mới vào cơ sở dữ liệu.

- Chức năng **Sửa thông tin nhân viên**: Chương trình cho phép sửa các thông của đối tượng nhân viên bất kì.

- Chức năng **Xóa nhân viên**: Chương trình thực hiện xóa nhân viên có *Mã nhân viên* ra khỏi cơ sở dữ liệu.

- Chức năng **Thêm hàng hóa mới**: Chương trình thực hiện thêm một mặt hàng mới vào cơ sở dữ liệu.

- Chức năng **Sửa thông tin mặt hàng**: Chương trình cho phép sửa các thông tin của đối tượng hàng hóa bất kì.

- Chức năng **Xóa hàng hóa**: Chương trình thực hiện xóa hàng hóa ra khỏi cơ sở dữ liệu.

- Chức năng **Thanh toán**: Sẽ được sử dụng khi có khách đến mua hàng và thực hiện thanh toán. Cụ thể, sau khi lựa các hàng hóa, khách sẽ đưa ra danh sách các sản phẩm khách mua bao gồm các thông tin dưới đây. Sau đó chương trình dựa trên danh sách các sản phẩm thực hiện tạo ra một hóa đơn để gửi trả lại cho khách.

    Danh sách sản phẩm khách mua bao gồm các thông tin sau:

    - Mã sản phẩm.
    - Số lượng mua (mỗi sản phẩm).

- Chức năng **Nhập hàng hóa**: Chương trình sẽ được cung cấp một danh sách các hàng hóa sẽ được nhập vào kho với một số thông tin sau đây. Chương trình thực hiện cập nhật số lượng các mặt hàng tương ứng.

    Danh sách sản phẩm nhập kho gồm các thông tin sau:

    - Ngày nhập kho (Định dạng DD/MM/YYYY).
    - Tên sản phẩm (Nếu là sản phẩm mới thì thêm vào cơ sở dữ liệu, ngược lại sẽ cập nhật số lượng vào sản phẩm đã có).
    - Số lượng sản phẩm.
    - Phân loại sản phẩm (Xem danh mục ở dưới).
    - Giá sản phẩm (Không quá $10^9$ VND).
    - Cân nặng sản phẩm (Không quá $10^9$ VND).
    - Ngày sản xuất (Định dạng DD/MM/YYYY).
    - Hạn sử dụng (Số nguyên không quá $12$).
    - Nhà sản xuất (Không quá $256$ kí tự).

- Chức năng **Thống kê các đơn hàng trong ngày**: Trả về một danh sách các thông tin của đơn hàng được thanh toán trong ngày. Danh sách bao gồm các thông tin sau:

    - Thời gian bán (định dạng DD/MM/YYYY và giờ/phút/giây).
    - Mã đơn hàng.
    - Danh sách các sản phẩm trong đơn hàng.

- Chức năng **Thống kê hàng trong kho**: In ra danh sách các thông tin của hàng hóa hiện có ở trong kho. Mỗi hàng hóa in ra đầy đủ các thông tin lưu trữ trong cơ sở dữ liệu.

- Chức năng **Thông kê** top $10$ hàng hóa được bán nhiều nhất theo ngày hoặc theo tháng hoặc theo năm. Trả về một danh sách gồm tối đa $10$ hàng hóa, mỗi hàng hóa có các thông tin đầy đủ của một đối tượng hàng hóa.

### Yêu cầu

- Thực hiện đầy đủ các chức năng đã được yêu cầu ở trên.
- Tạo giao diện người dùng (*User interface*) cho các chức năng nêu trên và các chức năng phụ khác nếu cần thiết.
- Cơ sở dữ liệu (thông tin sinh viên và thông tin các buổi sinh hoạt) sẽ được lưu dưới dạng file `*.txt`. Nếu có thể thì áp dụng cơ sở dữ liệu (database) vào để lưu trữ dữ liệu.
