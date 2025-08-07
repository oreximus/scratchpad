APIs list App panel:
Done 1. create-purchase-order //DRAFT //Admin, Manager, Supervisor
router.post("/create-purchase-order", verifyToken, schema.createPurchaseOrder, controllers.createPurchaseOrder);
Done 2. update-purchase-order //DRAFT //Admin, Manager, Supervisor
router.put("/update-purchase-order", verifyToken, schema.updatePurchaseOrder, controllers.updatePurchaseOrder);
Done 3. get-purchase-order-list
router.get("/get-purchase-order-list", verifyToken, controllers.getPurchaseOrderList);
Done 4. get-purchase-order-details
router.get("/get-purchase-order-details", verifyToken, controllers.getPurchaseOrderDetails);
Done 5. submit-purchase-order //PENDING_ADMIN_APPROVAL //Manager, Supervisor
router.post("/submit-purchase-order", verifyToken, schema.submitPurchaseOrder, controllers.submitPurchaseOrder);
Done 6. reject-purchase-order //REJECTED //Admin
router.post("/reject-purchase-order", verifyToken, schema.rejectPurchaseOrder, controllers.rejectPurchaseOrder);
Done 7. approve-purchase-order //APPROVED //Admin
router.post("/approve-purchase-order", verifyToken, schema.approvePurchaseOrder, controllers.approvePurchaseOrder);
Done 8. final-rejection-purchase-order //REJECTED_BY_ADMIN
router.post("/final-rejection-purchase-order", verifyToken, schema.finalRejectionPurchaseOrder, controllers.finalRejectionPurchaseOrder);
Done 9. cancel-purchase-order //CANCELLED_BY_ADMIN
router.post("/cancel-purchase-order", verifyToken, schema.cancelPurchaseOrder, controllers.cancelPurchaseOrder);
Done 10. final-approve-purchase-order //APPROVED_FINAL
router.post("/final-approve-purchase-order", verifyToken, schema.finalApprovePurchaseOrder, controllers.finalApprovePurchaseOrder); 11. receive-product-partial //PARTIALLY_RECEIVED
router.post("/receive-product-partial", verifyToken, schema.receiveProductPartial, controllers.receiveProductPartial); 12. complete-purchase-order //COMPLETED
router.post("/complete-purchase-order", verifyToken, schema.completePurchaseOrder, controllers.completePurchaseOrder);

APIs list Vendor panel:
Done 1. get-purchase-order-list
router.get("/get-purchase-order-list", verifyVendorToken, controllers.getPurchaseOrderList);
Done 2. get-organizations-in-purchase-orders
router.get("/get-organizations-in-purchase-orders", verifyToken, controllers.getOrganizationsInPurchaseOrders);
Done 3. get-projects-in-purchase-orders
router.get("/get-projects-in-purchase-orders", verifyToken, controllers.getProjectsInPurchaseOrders);
Done 4. vendor-reject-purchase-order //REJECTED_BY_VENDOR
router.post("/vendor-reject-purchase-order", verifyToken, schema.vendorRejectPurchaseOrder, controllers.vendorRejectPurchaseOrder);
Done 5. vendor-submit-response //VENDOR_SUBMITTED
router.post("/vendor-submit-response", verifyVendorToken, schema.vendorSubmitResponse, controllers.vendorSubmitResponse);
Done 6. dispatch-purchase-order //DISPATCHED
router.post("/dispatch-purchase-order", verifyVendorToken, schema.dispatchPurchaseOrder, controllers.dispatchPurchaseOrder); 7. vendor-again-submit-response //VENDOR_SUBMITTED
router.post("/vendor-again-submit-response", verifyVendorToken, schema.vendorAgainSubmitResponse, controllers.vendorAgainSubmitResponse);
Dashboard APIs: 1. get-purchase-order-dashboard
router.get("/get-purchase-order-dashboard", verifyToken, controllers.getPurchaseOrderDashboard);

1. DRAFT // performed by admin or manager or supervisor
2. PENDING_ADMIN_APPROVAL // performed by manager or supervisor
3. REJECTED // performed by admin
4. APPROVED // performed by admin
5. REJECTED_BY_VENDOR // performed by vendor
6. VENDOR_SUBMITTED // performed by vendor
7. REJECTED_BY_ADMIN // performed by admin
8. CANCELLED_BY_ADMIN // performed by admin
9. APPROVED_FINAL // performed by admin
10. DISPATCHED // performed by vendor
11. PARTIALLY_RECEIVED // performed by admin or manager or supervisor
12. COMPLETED // performed by admin or manager or supervisor

APIs list App panel:
// Define routes for purchase order, create PO and save as a DRAFT by Admin, Manager, Supervisor
// Admin can create PO and save as DRAFT or APPROVED
router.post("/create-purchase-order", verifyToken, uploadPOImage, schema.createPurchaseOrder, controllers.createPurchaseOrder);

    // Update purchase order, only Admin, Manager, Supervisor can update
    // Only DRAFT and PENDING_ADMIN_APPROVAL status can be updated
    // If the role is Admin, it can update PENDING_ADMIN_APPROVAL status
    router.post("/update-purchase-order", verifyToken, uploadPOImage, schema.updatePurchaseOrder, controllers.updatePurchaseOrder);

    // Get purchase order list, it is used to get purchase order list by Admin, Manager, Supervisor
    // Admin can get all purchase orders, Manager and Supervisor can get their own purchase orders
    router.post("/get-purchase-order-list", verifyToken, schema.getPurchaseOrderList, controllers.getPurchaseOrderList);

    // Get purchase order details, it is used to get purchase order details by Admin, Manager, Supervisor
    // Admin can get all purchase order details, Manager and Supervisor can get their own purchase order details
    router.get("/get-purchase-order-details/:po_id", verifyToken, schema.getPurchaseOrderDetails, controllers.getPurchaseOrderDetails);

    // Submit purchase order for admin approval, submitted by Manager, Supervisor. change status DRAFT to PENDING_ADMIN_APPROVAL
    router.post("/submit-purchase-order", verifyToken, schema.submitPurchaseOrder, controllers.submitPurchaseOrder);

    // Reject purchase order, it is used to reject purchase order by Admin, change status PENDING_ADMIN_APPROVAL to REJECTED
    router.post("/reject-purchase-order", verifyToken, schema.rejectPurchaseOrder, controllers.rejectPurchaseOrder);

    // approve-purchase-order it is used to approve purchase order by Admin, change status PENDING_ADMIN_APPROVAL to APPROVED
    // Admin can direclty approve purchase order, change status DRAFT to APPROVED
    router.post("/approve-purchase-order", verifyToken, schema.approvePurchaseOrder, controllers.approvePurchaseOrder);

    // Final rejection of purchase order, it is used to reject purchase order by Admin, change status VENDOR_SUBMITTED to REJECTED_BY_ADMIN
    router.post("/final-rejection-purchase-order", verifyToken, schema.finalRejectionPurchaseOrder, controllers.finalRejectionPurchaseOrder);

    // Cancel purchase order, it is used to cancel purchase order by Admin, change status VENDOR_SUBMITTED to CANCELLED_BY_ADMIN.
    // Vendor can submit again response on purchase order.
    router.post("/cancel-purchase-order", verifyToken, schema.cancelPurchaseOrder, controllers.cancelPurchaseOrder);

    // Final approve purchase order, it is used to approve purchase order by Admin, change status VENDOR_SUBMITTED to APPROVED_FINAL
    router.post("/final-approve-purchase-order", verifyToken, schema.finalApprovePurchaseOrder, controllers.finalApprovePurchaseOrder);

    // Partially receive products: This is used by Admin or the PO creator (Manager/Supervisor) to mark a partial product receipt and update the status to PARTIALLY_RECEIVED.
    router.post("/receive-product-partially", verifyToken, schema.receiveProductPartially, controllers.receiveProductPartially);

================
APIs list Vendor panel:
// It is used to get purchase order list by Vendor, He can access his all purchase orders and status will be APPROVED, VENDOR_SUBMITTED, APPROVED_FINAL, DISPATCHED, PARTIALLY_RECEIVED, COMPLETED, REJECTED_BY_ADMIN, REJECTED_BY_VENDOR, CANCELLED_BY_ADMIN
router.post("/get-purchase-order-list", verifyToken, schema.getPurchaseOrderList, controllers.getPurchaseOrderList);

    // get a list of organizations that are present in the purchase_order table — i.e., only those organizations that have at least one PO.
    router.get("/get-organizations-in-purchase-orders", verifyToken, controllers.getOrganizationsInPurchaseOrders);

    // get a list of projects that are present in the purchase_order table — i.e., only those projects that have at least one PO.
    router.post("/get-projects-in-purchase-orders", verifyToken, schema.getProjectsInPurchaseOrders, controllers.getProjectsInPurchaseOrders);

    // vendor submit response on purchase order, it is used to submit response on purchase order by Vendor, change status APPROVED to REJECTED_BY_VENDOR.
    router.post("/vendor-reject-purchase-order", verifyToken, schema.vendorRejectPurchaseOrder, controllers.vendorRejectPurchaseOrder);

    // vendor submit response on purchase order, it is used to submit response on purchase order by Vendor, change status APPROVED to VENDOR_SUBMITTED.
    router.post("/vendor-submit-response", verifyToken, uploadPOImage, schema.vendorSubmitResponse, controllers.vendorSubmitResponse);

    // Dispatch purchase order by Admin, it is used to dispatch purchase order by Admin, change status APPROVED_FINAL to DISPATCHED.
    router.post("/dispatch-purchase-order", verifyToken, schema.dispatchPurchaseOrder, controllers.dispatchPurchaseOrder);
